void init_tests();
void print(char* buffer);

#define TEST(NAME, COND) print(NAME); print(#COND); if((COND)) print("PASS\n"); else print("FAIL\n")
