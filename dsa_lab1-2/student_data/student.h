typedef struct Student student;

struct Student {
  char *id;
  double cgpa;
};

typedef struct List ll;
typedef struct StudentNode studNode;

struct List {
  int count;
  studNode *head;
};

struct StudentNode {
  student student;
  studNode *next;
};

void createArray(student *);
ll *createLL();

studNode *createNode();

student getFromArray(int, student *);

student getFromLL(int, ll *);

void addAtArray(int, student *);

void addAtLL(int, ll *);

void deleteAllArray(student *);

void deleteAllLL(ll *);
