#### PROI 23L

### Ogólne wymagania dotyczące zadania nr 2

# Proszę  zaimplementować  klasę  wskazaną  w  treści  zadania.
W  każdym  z  zadań  należy dobrać odpowiednie typy pól i wartości zwracanych metod oraz zaimplementować:
-odpowiedni(e) konstruktor(y),
-gettery i settery dla wszystkich pólniebędących kolekcjami,
-metody umożliwiające operowanie na kolekcjach i ich elementach:
-wyszukiwanie elementów  w  kolekcji(sprawdzanie,  czy  dany element  należy  do kolekcji),
-dodawanie nowych elementów do kolekcji (zakładamy, że dodawanie duplikatów jest niedopuszczalne),
-modyfikację  danego  elementu  kolekcji  (nie  jest  możliwa  modyfikacja  elementu, którego wcześniej nie było w kolekcji),
-usuwanie określonego elementu z kolekcji (nie jest możliwe usunięcie elementu, którego wcześniej nie było w kolekcji),
-zliczanie elementów kolekcji.

We wszystkich zadaniach zachodzi potrzeba użycia co  najmniej  jednej kolekcji oraz odwołań do obiektów innych klas.
Zgodnie z podejściem obiektowym, należałoby stworzyć wszystkie niezbędne klasy reprezentujące pojęcia pojawiające się w zadaniu,
słusznie byłoby też użyć rodzaju kolekcji pasującego do danego zadania. Dla uproszczenia, na potrzeby tego (i tylko tego) zadania,
można ograniczyć się do zastosowania typów wbudowanych (np. stringi vector).

Do reprezentacji kolekcji elementów proszę wówczas użyć wektorów z biblioteki standardowej C++ (z pliku <vector>),
a powiązane obiekty zastąpić symbolizującymi je zmiennymi typu string(np. jeśli w przypadku pisarza chcemy przechować kolekcję napisanych przez niego książek,
to na potrzeby tego zadania można przyjąć, że książka jest reprezentowana przez tytuł zapisywany jako string, a kolekcja –jako vector).
Wówczas  elementy  kolekcji  będą  rozpoznawane  na  podstawie  napisów  typu string(np. sprawdzenie, czy książka została napisana przez danego pisarza,
będzie polegać na sprawdzeniu, czy wektor książek autorstwa pisarza zawiera tytuł wyszukiwanej książki).

Uwaga:Powyższe uproszczenie jest dopuszczalne wyłącznie na potrzeby zadania nr 2 i nie może zostać zastosowane w kolejnych zadaniach ani w projekcie.

Dla wszystkich metod proszę przygotować testy jednostkowe, sprawdzające zachowanie klasy zarówno dla danych poprawnych, jak i niepoprawnych.
Każdą metodę należy przetestować na kilku różnych wartościach danych. Do  testów  jednostkowych  należy  użyć  biblioteki  do  tego  przeznaczonej,
np. Catch2(https://github.com/catchorg/Catch2),  opis  podstaw  jej  użycia  znajduje  się  pod  adresem https://github.com/catchorg/Catch2/blob/devel/docs/tutorial.md#top.
Jedno z rozwiązań polega na ściągnięciu kodu biblioteki (zawartej w całości w jednej parze plików: catch_amalgamated.hppi catch_amalgamated.cpp)
i  dodaniu tych  plikówdo  folderu  z  projektemtestowym. Można skorzystać z innej analogicznej biblioteki,
niedopuszczalne jest jednak wykonanie „testów” za pomocą instrukcji assertczy cout.

Ponadto, proszę napisać program wczytujący dane (wartości kolejnych pól obiektu) z argumentów wywołania programu,
tworzący na ich podstawie obiekt klasy z treści zadania i wypisujący wszystkie pola  tego  obiektu.

Proszę  zabezpieczyć  program  przed  wczytaniem  niepoprawnych  danych wejściowych (np. nieodpowiednia liczba argumentów, niepoprawna wartość argumentu).
W  wielu  przypadkach  konieczna będzie również konwersja wczytanych argumentów wywołania programudo innego typu, np. liczbowego.
Istnieją różne metody konwersji, można np. użyć obiektów typu stringstreamz pliku nagłówkowego<sstream>lub funkcji dostępnych w pliku<string>,
np. std::stod, std::stoi.Proszę zadbać o jakość kodu, w tym o przestrzeganie zaleceń podanych na początku semestru.