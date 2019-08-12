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
#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <IFSelect_GeneralModifier.hxx>
#include <TColStd_HSequenceOfInteger.hxx>
#include <IFSelect_AppliedModifiers.hxx>
#include <Standard_Type.hxx>
#include <IFSelect_SequenceOfGeneralModifier.hxx>
#include <Interface_IntList.hxx>

void bind_IFSelect_AppliedModifiers(py::module &mod){

py::class_<IFSelect_AppliedModifiers, opencascade::handle<IFSelect_AppliedModifiers>, Standard_Transient> cls_IFSelect_AppliedModifiers(mod, "IFSelect_AppliedModifiers", "This class allows to memorize and access to the modifiers which are to be applied to a file. To each modifier, is bound a list of integers (optionnal) : if this list is absent, the modifier applies to all the file. Else, it applies to the entities designated by these numbers in the produced file.");

// Constructors
cls_IFSelect_AppliedModifiers.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("nbmax"), py::arg("nbent"));

// Fields

// Methods
cls_IFSelect_AppliedModifiers.def("AddModif", (Standard_Boolean (IFSelect_AppliedModifiers::*)(const opencascade::handle<IFSelect_GeneralModifier> &)) &IFSelect_AppliedModifiers::AddModif, "Records a modifier. By default, it is to apply on all a produced file. Further calls to AddNum will restrict this. Returns True if done, False if too many modifiers are already recorded", py::arg("modif"));
cls_IFSelect_AppliedModifiers.def("AddNum", (Standard_Boolean (IFSelect_AppliedModifiers::*)(const Standard_Integer)) &IFSelect_AppliedModifiers::AddNum, "Adds a number of entity of the output file to be applied on. If a sequence of AddNum is called after AddModif, this Modifier will be applied on the list of designated entities. Else, it will be applied on all the file Returns True if done, False if no modifier has yet been added", py::arg("nument"));
cls_IFSelect_AppliedModifiers.def("Count", (Standard_Integer (IFSelect_AppliedModifiers::*)() const) &IFSelect_AppliedModifiers::Count, "Returns the count of recorded modifiers");
cls_IFSelect_AppliedModifiers.def("Item", [](IFSelect_AppliedModifiers &self, const Standard_Integer num, opencascade::handle<IFSelect_GeneralModifier> & modif, Standard_Integer & entcount){ Standard_Boolean rv = self.Item(num, modif, entcount); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, entcount); }, "Returns the description for applied modifier n0 <num> : the modifier itself, and the count of entities to be applied on. If no specific list of number has been defined, returns the total count of entities of the file If this count is zero, then the modifier applies to all the file (see below). Else, the numbers are then queried by calls to ItemNum between 1 and <entcount> Returns True if OK, False if <num> is out of range", py::arg("num"), py::arg("modif"), py::arg("entcount"));
cls_IFSelect_AppliedModifiers.def("ItemNum", (Standard_Integer (IFSelect_AppliedModifiers::*)(const Standard_Integer) const) &IFSelect_AppliedModifiers::ItemNum, "Returns a numero of entity to be applied on, given its rank in the list. If no list is defined (i.e. for all the file), returns <nument> itself, to give all the entities of the file Returns 0 if <nument> out of range", py::arg("nument"));
cls_IFSelect_AppliedModifiers.def("ItemList", (opencascade::handle<TColStd_HSequenceOfInteger> (IFSelect_AppliedModifiers::*)() const) &IFSelect_AppliedModifiers::ItemList, "Returns the list of entities to be applied on (see Item) as a HSequence (IsForAll produces the complete list of all the entity numbers of the file");
cls_IFSelect_AppliedModifiers.def("IsForAll", (Standard_Boolean (IFSelect_AppliedModifiers::*)() const) &IFSelect_AppliedModifiers::IsForAll, "Returns True if the applied modifier queried by last call to Item is to be applied to all the produced file. Else, <entcount> returned by Item gives the count of entity numbers, each one is queried by ItemNum");
cls_IFSelect_AppliedModifiers.def_static("get_type_name_", (const char * (*)()) &IFSelect_AppliedModifiers::get_type_name, "None");
cls_IFSelect_AppliedModifiers.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_AppliedModifiers::get_type_descriptor, "None");
cls_IFSelect_AppliedModifiers.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_AppliedModifiers::*)() const) &IFSelect_AppliedModifiers::DynamicType, "None");

// Enums

}