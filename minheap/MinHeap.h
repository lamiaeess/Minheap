//C++ programme d'implementation de min heap
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Template representant minheap
template <typename T>
class MinHeap {
private:
    vector<T> tableau; //vecteur qui est utilis� pour stocker les �l�ments de tas min
    int taille; //variable qui repr�sente la taille actuelle du tas min
    int capacite; //variable qui repr�sente la taille maximale du tas min

public:
    //Constructeur pour definir la capacite initiale du tas
    MinHeap(int capacite);

    //Fonction pour restaurer l'ordre du tas � l'indice i
    void heapify(int i);

    //Fonction pour cr�er un tas minimum � partir d'un tableau donn�
    void CreerHeap(const vector<T>& arr);

    //Fonction pour ins�rer un nouveau n�ud dans le tas minimum
    void InsererNoeud(T val);

    //Fonction pour obtenir la valeur la plus �lev�e du tas minimum
    T peek();

    //Fonction pour supprimer et retourner la valeur minimale du tas
    T RetournerMin();

    //Fonction pour supprimer un n�ud sp�cifique du tas
    void supprimerNoeud(T cle);

    //Fonction pour afficher les valeurs du tas minimum
    void afficherheap() const;
};

template<typename T>
MinHeap<T>::MinHeap(int capacite)
{
    this->taille = 0;
    this->capacite = capacite;
    this->tableau.resize(capacite);
}
/*
-D�terminer les enfants gauche et droit en utilisant les formules 2i+1 et 2i+2.
-Trouvez la plus petite valeur parmi le n�ud actuel, l'enfant gauche et l'enfant droit.
-Si le n�ud actuel n'est pas le plus petit, �changez-le avec le plus petit enfant.
-Continuez ce processus jusqu'� ce que la propri�t� heap soit satisfaite.
*/
template<typename T>
void MinHeap<T>::heapify(int i)
{
    //Initialiser le plus petit comme racine
    int smallest = i;
    //Trouver l'indice du fils gauche
    int gauche = 2 * i + 1;
    //rouver l'indice du fils droit
    int droit = 2 * i + 2;
    //Si le fils gauche est plus petit que la racine
    if (gauche < taille && tableau[gauche] < tableau[smallest])
        smallest = gauche;
    //Si le fils droit est plus petit que le plus petit trouv� jusqu'� pr�sent
    if (droit < taille && tableau[droit] < tableau[smallest])
        smallest = droit;
    //Si le plus petit n'est pas la racine
    if (smallest != i) {
        swap(tableau[i], tableau[smallest]);
        heapify(smallest);
    }
}

/*
-Commencez par le dernier n�ud non feuille (c'est-�-dire taille/2 - 1)et d�placez-vous vers le haut vers le n�ud racine.
-Appliquer heapify � chaque n�ud pour s'assurer qu'il satisfait la propri�t� heap.
-Continuez ce processus pour tous les n�uds jusqu'� la racine.
-Terminez le processus lorsque le tas entier est conforme � la structure du tas min.
*/
template<typename T>
void MinHeap<T>::CreerHeap(const vector<T>& arr)
{
    tableau = arr;
    capacite = arr.size();
    taille = capacite;

    //Appliquer heapify sur les n�uds de l'indice (n-1)/2.
    for (int i = (taille - 1) / 2; i >= 0; i--) {
        heapify(i);
    }
}
/*
-Augmentez la taille du tas de 1.
-Placez le nouveau n�ud � la fin du tableau.
-D�finissez i sur l'index du n�ud nouvellement ajout�.
-Alors que i n'est pas la racine et que la valeur du nouveau n�ud est inf�rieure � la valeur de son parent:
    -�changez le nouveau n�ud avec son parent.
    -Mettre � jour i vers l'index du parent.
*/
template<typename T>
void MinHeap<T>::InsererNoeud(T val)
{
    if (taille == capacite) {
        //Redimensionner le tas
        capacite *= 2;
        tableau.resize(capacite);
    }

    taille++;
    int i = taille - 1;
    tableau[i] = val;

    while (i != 0 && tableau[(i - 1) / 2] > tableau[i]) {
        swap(tableau[i], tableau[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}
/*
-V�rifiez si le tas est vide.
-Si le tas n'est pas vide, renvoyez l'�l�ment racine (le plus petit �l�ment d'un tas min).
-Si le tas est vide, retourner - 1.
*/
template<typename T>
T MinHeap<T>::peek()
{
    if (taille <= 0)
        return -1;  //Indique que le tas est vide

    return tableau[0];
}
/*
-V�rifiez si le tas est vide. Si c'est le cas, retournez - 1.
-Enregistrer l'�l�ment racine.
-Remplacez l'�l�ment racine par le dernier �l�ment du tas.
-Diminuez la taille du tas de 1.
-Appeler heapify sur la racine pour restaurer la propri�t� min heap.
-Retourne l'�l�ment racine d'origine.
*/
template<typename T>
T MinHeap<T>::RetournerMin()
{
    if (taille <= 0)
        return -1;  //Indique que le tas est vide
    if (taille == 1) {
        taille--;
        return tableau[0];
    }

    //Stocker la valeur minimale et la supprimer
    T racine = tableau[0];
    tableau[0] = tableau[taille - 1];
    taille--;
    //Appliquer heapify sur le n�ud racine apr�s la suppression
    heapify(0);
    return racine;
}
/*
-Localisez le n�ud que vous souhaitez supprimer en parcourant le tas.
-Enregistrez l'index de ce n�ud.
-Remplacez le n�ud cible par le dernier n�ud du tas.
-R�duire la taille du tas de 1.
-Appliquez la fonction heapify � l'index o� le n�ud a �t� supprim� pour restaurer la propri�t� min heap.
*/
template<typename T>
void MinHeap<T>::supprimerNoeud(T cle)
{
    //Trouver l'indice de la cle
    int index = -1;
    for (int i = 0; i < taille; ++i) {
        if (tableau[i] == cle) {
            index = i;
            break;
        }
    }
    //Si la cle n'est pas trouvee, retourner
    if (index == -1) {
        cout << "cle non trouvee" << endl;
        return;
    }

    if (index == taille - 1) {
        taille--;
        return;
    }

    //deplacer le dernier element � l'indice de la cle a supprimer
    tableau[index] = tableau[taille - 1];
    taille--;

    //Appliquer  heapify vers le bas pour restaurer l'ordre du tas min
    heapify(index);
}

template<typename T>
void MinHeap<T>::afficherheap() const
{
    for (int i = 0; i < taille; ++i)
        cout << tableau[i] << " ";
    cout << endl;
}
