#ifndef LLFIFO_H_INCLUDED
#define LLFIFO_H_INCLUDED

typedef struct llfifo_s llfifo_t;

llfifo_t *llfifo_create(int capacity);
int llfifo_enqueue(llfifo_t *fifo, void *element);
void *llfifo_dequeue(llfifo_t *fifo);
int llfifo_length(llfifo_t *fifo);
int llfifo_capacity(llfifo_t *fifo);

#endif // LLFIFO_H_INCLUDED
