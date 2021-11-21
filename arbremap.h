/* Squelette pour classe générique ArbreMap<K, V>.
 * Lab8 -- Dictionnaires et Arbres binaires de recherche
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes
 * http://CRIA2.uqam.ca/INF3105/lab8/
 *
 */
#if !defined(__ARBREMAP_H__)
#define __ARBREMAP_H__
#include "arbreavl.h"

template <class K, class V>
class ArbreMap {
  public:
    bool contient(const K&) const;

    void enlever(const K&);
    void vider();
    bool vide() const;

    const V& operator[] (const K&) const;
    V& operator[] (const K&);

  private:
    class Entree{
        public:
            Entree(const K& c):cle(c),valeur(){}
            K cle;
            V valeur;
            bool operator < (const Entree& e) const { return cle < e.cle; }
    };
    ArbreAVL<Entree> entrees;

    public:
        class Iterateur{
            public:
                Iterateur(ArbreMap& a) : iter(a.entrees.debut()){}
                Iterateur(typename ArbreAVL<Entree>::Iterateur i) : iter(i){}
                operator bool() const {return iter.operator bool();};
                Iterateur& operator++() {++iter; return *this;}
                const K& cle() const {return (*iter).cle;}
                V& valeur() {return(V&)(*iter).valeur;}

            private:
                typename ArbreAVL<Entree>::Iterateur iter;
        };
        Iterateur debut() {return Iterateur(*this);}
        Iterateur fin() {return Iterateur(entrees.fin());}
        Iterateur rechercher(const K& cle) {return Iterateur(entrees.rechercher(cle));}
};

template <class K, class V>
void ArbreMap<K,V>::vider(){
    entrees.vider();
}

template <class K, class V>
bool ArbreMap<K,V>::vide() const{
    
    return entrees.vide();
}

template <class K, class V>
void ArbreMap<K,V>::enlever(const K& c)
{
    entrees.enlever(c);
}

template <class K, class V>
bool ArbreMap<K,V>::contient(const K& c) const
{
    return entrees.contient(c);
}

template <class K, class V>
const V& ArbreMap<K,V>::operator[] (const K& c)  const
{
    typename ArbreAVL<Entree>::Iterateur iter=entrees.rechercher(c);
    return entrees[iter].valeur;
}

template <class K, class V>
V& ArbreMap<K,V>::operator[] (const K& c) 
{
    typename ArbreAVL<Entree>::Iterateur iter=entrees.rechercher(Entree(c));
    if(!iter){
        entrees.inserer(Entree(c));
        iter = entrees.rechercher(c);
    }
    return entrees[iter].valeur;
}


#endif
