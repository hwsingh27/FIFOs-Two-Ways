#ifndef CBFIFO_H_INCLUDED
#define CBFIFO_H_INCLUDED

size_t cbfifo_enqueue(void *buf, size_t nbyte);
size_t cbfifo_dequeue(void *buf, size_t nbyte);
size_t cbfifo_length();
size_t cbfifo_capacity();


#endif // CBFIFO_H_INCLUDED
