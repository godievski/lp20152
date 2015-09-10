/*  CREANDO PLANTILLAS!!!  */

template <typename M>
M maximo (M valor1, M valor2, M valor3)
{
  M max = valor1;
  max = max > valor2 ? max : valor2;
  max = max > valor3 ? max : valor3;

  return max;
}


template char maximo (char, char, char);
template int maximo (int, int, int);
template double maximo (double, double, double);
