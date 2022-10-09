#pragma once

#include <cstdio>
#include <string>





#define GET_STRING_FROM_TOKEN(tokens) #tokens



#ifdef WINDOWS
#define DEBUGBREAK __debugbreak()
#endif

#ifdef LINUX
#define DEBUGBREAK __builtin_trap()
#endif

#ifdef DEBUG
#define ASSERT(condition)  {\
								if (!(condition))\
								{\
									printf("%s\n", GET_STRING_FROM_TOKEN(condition));\
									printf("Erorr in file: %s in function: %s\n", __FILE__, __FUNCTION__);\
									DEBUGBREAK;										\
								}														\
							}
#else
#define ASSERT(condition) ;
#endif

  
/*
#ifdef DEBUG
#ifdef WINDOWS
#define ASSERT(condition)			{\
										if (!(condition))\
										{\
											printf("%s\n", GET_STRING_FROM_TOKEN(condition));\
											printf("Erorr in file: %s in function: %s\n", __FILE__, __FUNCTION__);\
											__debugbreak();										\
										}														\
									}
#endif

#ifdef LINUX
#define ASSERT(condition)			{\
										if(!(condition))\
										{\
											printf("%s\n", GET_STRING_FROM_TOKEN(condition));\
											printf("Erorr in file: %s in function: %s\n", __FILE__, __FUNCTION__);\
											__builtin_trap();\
										}\
									}
#endif

#endif
*/