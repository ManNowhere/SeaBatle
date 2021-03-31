#ifndef ALLFIELD_H
#define ALLFIELD_H

#include <vector>

//class All_field//содержит игровые поля
//{
//   public:
//   All_field() : field_(10, std::vector<int>(10, 0))
//   {}
//   ~All_field(){}


//   std::vector<std::vector<int>>& get_vector()//создается игровое поле
//   {
//       return field_;
//   }

//private:

//   std::vector<std::vector<int>> field_;

//};





class All_field//содержит игровые поля
{
   public:
   All_field() : field_(10, std::vector<int>(10, 0))
   {}
   ~All_field(){}


   std::vector<std::vector<int>>& get_vector()//создается игровое поле
   {
       return field_;
   }

private:

   std::vector<std::vector<int>> field_;

};








#endif // ALLFIELD_H
