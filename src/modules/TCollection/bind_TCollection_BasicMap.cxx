/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC
Copyright (C) 2019 Trevor Laughlin and the pyOCCT contributors

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include <pyOCCT_Common.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_OStream.hxx>
#include <TCollection_BasicMapIterator.hxx>
#include <TCollection_BasicMap.hxx>

void bind_TCollection_BasicMap(py::module &mod){

py::class_<TCollection_BasicMap, std::unique_ptr<TCollection_BasicMap, Deleter<TCollection_BasicMap>>> cls_TCollection_BasicMap(mod, "TCollection_BasicMap", "Root class of all the maps, provides utilitites for managing the buckets. Maps are dynamically extended data structures where data is quickly accessed with a key. General properties of maps - Map items may be (complex) non-unitary data; they may be difficult to manage with an array. Moreover, the map allows a data structure to be indexed by complex data. - The size of a map is dynamically extended. So a map may be first dimensioned for a little number of items. Maps avoid the use of large and quasi-empty arrays. - The access to a map item is much faster than the one to a sequence, a list, a queue or a stack item. - The access time to a map item may be compared with the one to an array item. First of all, it depends on the size of the map. It also depends on the quality of a user redefinable function (the hashing function) to find quickly where the item is. - The exploration of a map may be of better performance than the exploration of an array because the size of the map is adapted to the number of inserted items. These properties explain why maps are commonly used as internal data structures for algorithms. Definitions - A map is a data structure for which data is addressed by keys. - Once inserted in the map, a map item is referenced as an entry of the map. - Each entry of the map is addressed by a key. Two different keys address two different entries of the map. - The position of an entry in the map is called a bucket. - A map is dimensioned by its number of buckets, i.e. the maximum number of entries in the map. The performance of a map is conditioned by the number of buckets. - The hashing function transforms a key into a bucket index. The number of values that can be computed by the hashing function is equal to the number of buckets of the map. - Both the hashing function and the equality test between two keys are provided by a hasher object. - A map may be explored by a map iterator. This exploration provides only inserted entries in the map (i.e. non empty buckets). Collections' generic maps The Collections component provides numerous generic derived maps. - These maps include automatic management of the number of buckets: they are automatically resized when the number of keys exceeds the number of buckets. If you have a fair idea of the number of items in your map, you can save on automatic resizing by specifying a number of buckets at the time of construction, or by using a resizing function. This may be considered for crucial optimization issues. - Keys, items and hashers are parameters of these generic derived maps. - TCollection_MapHasher class describes the functions required by any hasher which is to be used with a map instantiated from the Collections component. - An iterator class is automatically instantiated at the time of instantiation of a map provided by the Collections component if this map is to be explored with an iterator. Note that some provided generic maps are not to be explored with an iterator but with indexes (indexed maps).");

// Constructors

// Fields

// Methods
// cls_TCollection_BasicMap.def_static("operator new_", (void * (*)(size_t)) &TCollection_BasicMap::operator new, "None", py::arg("theSize"));
// cls_TCollection_BasicMap.def_static("operator delete_", (void (*)(void *)) &TCollection_BasicMap::operator delete, "None", py::arg("theAddress"));
// cls_TCollection_BasicMap.def_static("operator new[]_", (void * (*)(size_t)) &TCollection_BasicMap::operator new[], "None", py::arg("theSize"));
// cls_TCollection_BasicMap.def_static("operator delete[]_", (void (*)(void *)) &TCollection_BasicMap::operator delete[], "None", py::arg("theAddress"));
// cls_TCollection_BasicMap.def_static("operator new_", (void * (*)(size_t, void *)) &TCollection_BasicMap::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TCollection_BasicMap.def_static("operator delete_", (void (*)(void *, void *)) &TCollection_BasicMap::operator delete, "None", py::arg(""), py::arg(""));
cls_TCollection_BasicMap.def("NbBuckets", (Standard_Integer (TCollection_BasicMap::*)() const) &TCollection_BasicMap::NbBuckets, "Returns the number of buckets in <me>.");
cls_TCollection_BasicMap.def("Extent", (Standard_Integer (TCollection_BasicMap::*)() const) &TCollection_BasicMap::Extent, "Returns the number of keys already stored in <me>.");
cls_TCollection_BasicMap.def("IsEmpty", (Standard_Boolean (TCollection_BasicMap::*)() const) &TCollection_BasicMap::IsEmpty, "Returns True when the map contains no keys. This is exactly Extent() == 0.");
cls_TCollection_BasicMap.def("Statistics", (void (TCollection_BasicMap::*)(Standard_OStream &) const) &TCollection_BasicMap::Statistics, "Prints on <S> usefull statistics about the map <me>. It can be used to test the quality of the hashcoding.", py::arg("S"));

// Enums

}