PROI 23L

Ogólne wymagania dotyczące zadania nr 4

Proszę  zaproponować  klasy  oraz  ich  pola  i  metody  niezbędne  do  zamodelowania  problemu przedstawionego w treści zadania.

Tematy sformułowane są w sposób ogólny i wymagają twórczego rozwinięcia.

W szczególności, w każdym z zadań należy:

1.zaproponować hierarchię klas dla problemu postawionego w treści zadania;
2.zdefiniować metody wirtualne, których implementacja w każdej z klas potomnych jest inna. Należy samodzielnie zaproponować
szczegółowy algorytm działania metody określonej w treści zadania (np. sposobu wyznaczania pensji dla każdej z kategorii pracowników).
Metoda wirtualna w klasie bazowej może, ale nie musi, być czysto wirtualna –co jest przydatne,
kiedy sensowne  implementacje da się zaproponować tylko dla klas potomnych, a nie dla klasy bazowej;

3.stworzyć klasę reprezentującą „bazę danych” wszystkich obiektów należących do wcześniej przygotowanej hierarchii klas.
Klasa ta powinna umożliwiać polimorficzne wykonanie metod wirtualnych dla wszystkich obiektów klas bazowej i potomnych.
Uwaga: polimorficzne wykonanie funkcji jest możliwe przy użyciu wskaźników lub referencji do klasy bazowej.
Na potrzeby tego zadania klasa reprezentująca „bazę danych” powinna przechowywać jedną kolekcję inteligentnych wskaźników
(ang. smart pointers, zalecany std::unique_ptr) do obiektów klasy bazowej oraz udostępniać metody do dodawania i usuwania elementów
(które mogą być obiektami klasy bazowej lub pochodnych) oraz do wywołania każdej z metod polimorficznych  na wszystkich obiektach.
Proszę nie używać „zwykłych” wskaźników.

Ponadto, dla tak zdefiniowanych klas proszę napisać:
1.testy jednostkowe;
2.program  z prostym  menu  tekstowym,  który  w  sposób interakcyjny będzie  umożliwiał tworzenie i usuwanie
obiektów klas bazowej i potomnych oraz polimorficzne wywołanie określonych metod na całej zawartości „bazy danych”.