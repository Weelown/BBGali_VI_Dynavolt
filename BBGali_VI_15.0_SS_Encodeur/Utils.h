#ifndef Utils_h
#define Utils_h


typedef struct Element_table
{
  unsigned int m_x_debut;
  unsigned int m_y_debut;
  unsigned int m_x_fin;
  unsigned int m_y_fin;
}Element_table;

void init_element_table(Element_table* Objet);
void coord_pc(Robot& monRobot);
void demarer_avaler_balle();
void demarer_canon();
void couper_avaler_balle();
void couper_canon();

#endif