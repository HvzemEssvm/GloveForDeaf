#ifndef GLOVEMAPPER_H
#define	GLOVEMAPPER_H

typedef char* String;
// for 3^5 possible combinations then we have 243 possible Combination = 0 -> 242
#define combinatorics 243

typedef struct
{
  int sentenceAddress[combinatorics];
  void(*addAddress)(gloveMapper_t*,int[],uint16_t);
  uint16_t(*getAddress)(const gloveMapper_t*,int[]);
}
gloveMapper_t;

void GLOVEMAPPER_INIT(gloveMapper_t* mapper);

#endif	/* GLOVEMAPPER_H */

