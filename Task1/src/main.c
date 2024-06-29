#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define FILE_NAME "output.txt"
#define STRING_TO_WRITE "String from file"
#define STRING_LENGTH 16

void write_string_to_file(const char* filename, const char* str);
void read_string_from_file_reverse(const char* filename, char* buffer);

int main() {
  char buffer[STRING_LENGTH + 1];

  write_string_to_file(FILE_NAME, STRING_TO_WRITE);
  read_string_from_file_reverse(FILE_NAME, buffer);

  printf("Перевернутая строка: %s\n", buffer);

  return 0;
}

void write_string_to_file(const char* filename, const char* str) {
  int file = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (file < 0) {
    perror("Ошибка при открытии файла для записи");
    return;
  }
  if (write(file, str, STRING_LENGTH) != STRING_LENGTH) {
    perror("Ошибка при записи в файл");
    close(file);
    return;
  }

  fsync(file);
  close(file);
}

void read_string_from_file_reverse(const char* filename, char* buffer) {
  int file = open(filename, O_RDONLY);

  if (file < 0) {
    perror("Ошибка при открытии файла для чтения");
    return;
  }

  for (int i = 0; i < STRING_LENGTH; i++) {
    if (lseek(file, -1 - i, SEEK_END) == (off_t)-1) {
      perror("Ошибка при перемещении указателя в файле");
      close(file);
      return;
    }

    if (read(file, &buffer[i], 1) != 1) {
      perror("Ошибка при чтении из файла");
      close(file);
      return;
    }
  }

  buffer[STRING_LENGTH] = '\0';
  close(file);
}
