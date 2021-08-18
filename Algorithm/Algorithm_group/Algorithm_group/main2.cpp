

void ringbuff_init(ring_buffer *ringbuff, int capacity, int size);
void ringbuff_push_back(ring_buffer *ringbuff, const void *item);
void ringbuff_popup(ring_buffer *ringbuff, void *item);
void ringbuff_printall(ring_buffer *ringbuff);
void ringbuff_free(ring_buffer *ringbuff);




volatile int iCapacity = 50;
volatile bool bKeepwhile = true;

static ring_buffer* ring_buff = NULL;

void *producer(void *arg)
{

	while (true)
	{
		
		ringbuff_push_back(ring_buff);

	}
} //end of producer

void *consumer(void *arg)
{
	volatile int i = 1;
	while (bKeepwhile) {

		
		ringbuff_popup(ring_buff);
	
	}
}//end of consume

int main(int argc, void* argv[])
{
	

	pthread_create(&thread1, NULL, producer, (void *)"thread1");
	pthread_create(&thread2, NULL, consumer, (void *)"thread2");

	pthread_join(producer_thread1, NULL);
	pthread_join(consumer_thread2, NULL);


	ringbuff_free(ring_buff);
} //end of main
