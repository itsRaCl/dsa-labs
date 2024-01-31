#include "hotel.h"

HOTEL *create_new_hotel(char *name, char *address,
                        unsigned int occupied_rooms) {
  HOTEL *h = malloc(sizeof(HOTEL));
  h->name = name;
  h->address = address;
  h->occupied_rooms = occupied_rooms;
  if (occupied_rooms) {
    h->occupant_data = calloc(occupied_rooms, sizeof(VISITOR));
    for (int i = 0; i < occupied_rooms; i++) {
      char *visitor_name = (char *)malloc(1000 * sizeof(char));

      int visitor_age;
      printf("Enter the name of occupant of room %d: ", i);
      fgets(visitor_name, 1000, stdin);
      printf("%c", visitor_name[4]);
      printf("Enter the age of occupant of room %d: ", i);
      scanf("%d", &visitor_age);
      h->occupant_data[i].name = visitor_name;
      h->occupant_data[i].age = visitor_age;
      getchar();
    }
  }

  return h;
}

int main() {
  HOTEL *hotel = create_new_hotel("The Grand Hotel", "Testing", 3);
  printf("%s\n%s\n%d", hotel->name, hotel->address, hotel->occupied_rooms);
  return 0;
}
