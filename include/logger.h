#ifndef LOGGER_H
#define LOGGER_H

typedef enum { INFO, WARNING, ERROR } Log_Type;

void logger(Log_Type type, const char* msg);
void log_file(Log_Type type, const char* msg);
void log_stdout(Log_Type type, const char* msg);

#endif