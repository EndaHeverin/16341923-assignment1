


typedef struct genericlistElementStruct {
	char* data;
	size_t size;
	struct genericlistElementStruct* next;
} genericlistElement;

genericlistElement* createEl(char* data, size_t size);

void traverse(genericlistElement* start);


genericlistElement* insertAfter(genericlistElement* after, char* data, size_t size);

void printChar(void* data);

void deleteAfter(genericlistElement* after);

int length(genericlistElement* list);

void push(genericlistElement** list, char* data, size_t size);

genericlistElement* pop(genericlistElement** list);

void enqueue(genericlistElement** list, char* data, size_t size);

genericlistElement* dequeue(genericlistElement* list);