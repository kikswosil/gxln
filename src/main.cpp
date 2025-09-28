#include "ui/cli.hpp"

int main(int argc, char *argv[]) {
  UI *ui = new CLI();
  ui->run(argc, argv);
  delete ui;
  return 0;
}
