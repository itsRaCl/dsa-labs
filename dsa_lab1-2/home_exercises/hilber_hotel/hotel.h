#include <stdio.h>
#include <stdlib.h>

typedef struct hotel HOTEL;
typedef struct visitor VISITOR;

struct hotel {
  char *name;
  char *address;
  unsigned int occupied_rooms;
  VISITOR *occupant_data;
};

struct visitor {
  char *name;
  unsigned short age;
};

void append_new_visitor(HOTEL *hotel);

void prepend_new_visitor(HOTEL *hotel);

void empty_room(HOTEL *hotel, unsigned int room_no);
