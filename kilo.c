/*** includes ***/
#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>

/*** defines ***/
#define CTRL_KEY(k) ((k) & 0x1f)

/*** data ***/

struct editor_config {
    struct termios orig_termios;
    int screenrows;
    int screencols;
};

struct editor_config E;

/*** terminal **/
void die(const char *s) {
    perror(s);
    exit(1);
}

void disable_raw_mode() {
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &E.orig_termios) == -1)
        die("tcsetattr disable_raw_mode");
}

void enable_raw_mode() {
    if (tcgetattr(STDIN_FILENO, &E.orig_termios)) die("tcgetattr enable_raw_mode");
    atexit(disable_raw_mode);
    struct termios raw = E.orig_termios;
    raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
    raw.c_oflag &= ~(OPOST);
    raw.c_cflag |= (CS8);
    raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
    raw.c_cc[VMIN] = 0;
    raw.c_cc[VTIME] = 1;
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1) die("tcsetattr enable_raw_mode");
}

char editor_read_key() {
    int nread;
    char c;
    while ((nread = read(STDIN_FILENO, &c, 1)) != 1) {
        if (nread == -1 && errno != EAGAIN) die("read");
    }
    return c;
}

void editor_process_keypress() {
    char c = editor_read_key();
    switch (c) {
        case CTRL_KEY('q'):
            exit(0);
            break;
    }
}

void editor_position_key() {
    write(STDIN_FILENO, "\x1b[H", 3);
}

void editor_draw_rows() {
    for (int i = 0; i <= E.screenrows; i++) {
        write(STDIN_FILENO, "~\r\n", 3);
    }
}

void editor_refresh_screen() {
    write(STDIN_FILENO, "\x1b[2J", 4);
    editor_position_key();
    editor_draw_rows();
    editor_position_key();
}

int get_window_size(int *rows, int *cols) {
    struct winsize ws;
    if (ioctl(STDIN_FILENO, TIOCGWINSZ, &ws) == -1 || ws.ws_col == 0) {
        return -1;
    } else {
        *cols = ws.ws_col;
        *rows = ws.ws_row;
        return 0;
    }
}

/*** init ***/

void init_editor() {
  if (get_window_size(&E.screenrows, &E.screencols) == -1) die("getWindowSize");
}

int main() {
    enable_raw_mode();
    init_editor();

    while (1) {
        editor_refresh_screen();
        editor_process_keypress();
    }

    return 0;
}
