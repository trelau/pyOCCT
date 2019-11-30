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
#include <Standard_TypeDef.hxx>
#include <TopLoc_Location.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Handle.hxx>
#include <TopLoc_Datum3D.hxx>
#include <Standard.hxx>
#include <TopLoc_ItemLocation.hxx>
#include <TopLoc_SListOfItemLocation.hxx>
#include <TopLoc_SListNodeOfItemLocation.hxx>
#include <gp_Trsf.hxx>
#include <NCollection_DefaultHasher.hxx>
#include <TopLoc_MapLocationHasher.hxx>
#include <NCollection_IndexedMap.hxx>
#include <TopLoc_IndexedMapOfLocation.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Std.hxx>
#include <Standard_Type.hxx>
#include <NCollection_Map.hxx>
#include <TopLoc_MapOfLocation.hxx>
#include <bind_NCollection_DefaultHasher.hxx>
#include <bind_NCollection_IndexedMap.hxx>
#include <bind_NCollection_Map.hxx>

PYBIND11_MODULE(TopLoc, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.gp");
py::module::import("OCCT.NCollection");

// FUNCTION: HASHCODE
mod.def("HashCode", (Standard_Integer (*) (const TopLoc_Location &, const Standard_Integer)) &HashCode, "Computes a hash code for the given location, in the range [1, theUpperBound]", py::arg("theLocation"), py::arg("theUpperBound"));

// FUNCTION: SHALLOWDUMP
mod.def("ShallowDump", (void (*) (const TopLoc_Location &, Standard_OStream &)) &ShallowDump, "None", py::arg("me"), py::arg("S"));

mod.def("ShallowDump", (void (*) (const opencascade::handle<TopLoc_Datum3D> &, Standard_OStream &)) &ShallowDump, "None", py::arg("me"), py::arg("S"));

// CLASS: TOPLOC_SLISTOFITEMLOCATION
py::class_<TopLoc_SListOfItemLocation> cls_TopLoc_SListOfItemLocation(mod, "TopLoc_SListOfItemLocation", "An SListOfItemLocation is a LISP like list of Items. An SListOfItemLocation is : . Empty. . Or it has a Value and a Tail which is an other SListOfItemLocation.");

// Constructors
cls_TopLoc_SListOfItemLocation.def(py::init<>());
cls_TopLoc_SListOfItemLocation.def(py::init<const TopLoc_ItemLocation &, const TopLoc_SListOfItemLocation &>(), py::arg("anItem"), py::arg("aTail"));
cls_TopLoc_SListOfItemLocation.def(py::init<const TopLoc_SListOfItemLocation &>(), py::arg("Other"));
// cls_TopLoc_SListOfItemLocation.def(py::init<TopLoc_SListOfItemLocation &&>(), py::arg("theOther"));

// Methods
// cls_TopLoc_SListOfItemLocation.def_static("operator new_", (void * (*)(size_t)) &TopLoc_SListOfItemLocation::operator new, "None", py::arg("theSize"));
// cls_TopLoc_SListOfItemLocation.def_static("operator delete_", (void (*)(void *)) &TopLoc_SListOfItemLocation::operator delete, "None", py::arg("theAddress"));
// cls_TopLoc_SListOfItemLocation.def_static("operator new[]_", (void * (*)(size_t)) &TopLoc_SListOfItemLocation::operator new[], "None", py::arg("theSize"));
// cls_TopLoc_SListOfItemLocation.def_static("operator delete[]_", (void (*)(void *)) &TopLoc_SListOfItemLocation::operator delete[], "None", py::arg("theAddress"));
// cls_TopLoc_SListOfItemLocation.def_static("operator new_", (void * (*)(size_t, void *)) &TopLoc_SListOfItemLocation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopLoc_SListOfItemLocation.def_static("operator delete_", (void (*)(void *, void *)) &TopLoc_SListOfItemLocation::operator delete, "None", py::arg(""), py::arg(""));
cls_TopLoc_SListOfItemLocation.def("Assign", (TopLoc_SListOfItemLocation & (TopLoc_SListOfItemLocation::*)(const TopLoc_SListOfItemLocation &)) &TopLoc_SListOfItemLocation::Assign, "Sets a list from an other one. The lists are shared. The list itself is returned.", py::arg("Other"));
// cls_TopLoc_SListOfItemLocation.def("operator=", (TopLoc_SListOfItemLocation & (TopLoc_SListOfItemLocation::*)(const TopLoc_SListOfItemLocation &)) &TopLoc_SListOfItemLocation::operator=, "Assignment", py::arg("Other"));
// cls_TopLoc_SListOfItemLocation.def("operator=", (TopLoc_SListOfItemLocation & (TopLoc_SListOfItemLocation::*)(TopLoc_SListOfItemLocation &&)) &TopLoc_SListOfItemLocation::operator=, "Move operator", py::arg("theOther"));
cls_TopLoc_SListOfItemLocation.def("IsEmpty", (Standard_Boolean (TopLoc_SListOfItemLocation::*)() const) &TopLoc_SListOfItemLocation::IsEmpty, "Returne true if this list is empty");
cls_TopLoc_SListOfItemLocation.def("Clear", (void (TopLoc_SListOfItemLocation::*)()) &TopLoc_SListOfItemLocation::Clear, "Sets the list to be empty.");
cls_TopLoc_SListOfItemLocation.def("Value", (const TopLoc_ItemLocation & (TopLoc_SListOfItemLocation::*)() const) &TopLoc_SListOfItemLocation::Value, "Returns the current value of the list. An error is raised if the list is empty.");
cls_TopLoc_SListOfItemLocation.def("Tail", (const TopLoc_SListOfItemLocation & (TopLoc_SListOfItemLocation::*)() const) &TopLoc_SListOfItemLocation::Tail, "Returns the current tail of the list. On an empty list the tail is the list itself.");
cls_TopLoc_SListOfItemLocation.def("Construct", (void (TopLoc_SListOfItemLocation::*)(const TopLoc_ItemLocation &)) &TopLoc_SListOfItemLocation::Construct, "Replaces the list by a list with <anItem> as Value and the list <me> as tail.", py::arg("anItem"));
cls_TopLoc_SListOfItemLocation.def("ToTail", (void (TopLoc_SListOfItemLocation::*)()) &TopLoc_SListOfItemLocation::ToTail, "Replaces the list <me> by its tail.");
cls_TopLoc_SListOfItemLocation.def("More", (Standard_Boolean (TopLoc_SListOfItemLocation::*)() const) &TopLoc_SListOfItemLocation::More, "Returns True if the iterator has a current value. This is !IsEmpty()");
cls_TopLoc_SListOfItemLocation.def("Next", (void (TopLoc_SListOfItemLocation::*)()) &TopLoc_SListOfItemLocation::Next, "Moves the iterator to the next object in the list. If the iterator is empty it will stay empty. This is ToTail()");

// CLASS: TOPLOC_LOCATION
py::class_<TopLoc_Location> cls_TopLoc_Location(mod, "TopLoc_Location", "A Location is a composite transition. It comprises a series of elementary reference coordinates, i.e. objects of type TopLoc_Datum3D, and the powers to which these objects are raised.");

// Constructors
cls_TopLoc_Location.def(py::init<>());
cls_TopLoc_Location.def(py::init<const gp_Trsf &>(), py::arg("T"));
cls_TopLoc_Location.def(py::init<const opencascade::handle<TopLoc_Datum3D> &>(), py::arg("D"));

// Methods
// cls_TopLoc_Location.def_static("operator new_", (void * (*)(size_t)) &TopLoc_Location::operator new, "None", py::arg("theSize"));
// cls_TopLoc_Location.def_static("operator delete_", (void (*)(void *)) &TopLoc_Location::operator delete, "None", py::arg("theAddress"));
// cls_TopLoc_Location.def_static("operator new[]_", (void * (*)(size_t)) &TopLoc_Location::operator new[], "None", py::arg("theSize"));
// cls_TopLoc_Location.def_static("operator delete[]_", (void (*)(void *)) &TopLoc_Location::operator delete[], "None", py::arg("theAddress"));
// cls_TopLoc_Location.def_static("operator new_", (void * (*)(size_t, void *)) &TopLoc_Location::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopLoc_Location.def_static("operator delete_", (void (*)(void *, void *)) &TopLoc_Location::operator delete, "None", py::arg(""), py::arg(""));
cls_TopLoc_Location.def("IsIdentity", (Standard_Boolean (TopLoc_Location::*)() const) &TopLoc_Location::IsIdentity, "Returns true if this location is equal to the Identity transformation.");
cls_TopLoc_Location.def("Identity", (void (TopLoc_Location::*)()) &TopLoc_Location::Identity, "Resets this location to the Identity transformation.");
cls_TopLoc_Location.def("FirstDatum", (const opencascade::handle<TopLoc_Datum3D> & (TopLoc_Location::*)() const) &TopLoc_Location::FirstDatum, "Returns the first elementary datum of the Location. Use the NextLocation function recursively to access the other data comprising this location. Exceptions Standard_NoSuchObject if this location is empty.");
cls_TopLoc_Location.def("FirstPower", (Standard_Integer (TopLoc_Location::*)() const) &TopLoc_Location::FirstPower, "Returns the power elevation of the first elementary datum. Exceptions Standard_NoSuchObject if this location is empty.");
cls_TopLoc_Location.def("NextLocation", (const TopLoc_Location & (TopLoc_Location::*)() const) &TopLoc_Location::NextLocation, "Returns a Location representing <me> without the first datum. We have the relation :");
cls_TopLoc_Location.def("Transformation", (const gp_Trsf & (TopLoc_Location::*)() const) &TopLoc_Location::Transformation, "Returns the transformation associated to the coordinate system.");
cls_TopLoc_Location.def("Inverted", (TopLoc_Location (TopLoc_Location::*)() const) &TopLoc_Location::Inverted, "Returns the inverse of <me>.");
cls_TopLoc_Location.def("Multiplied", (TopLoc_Location (TopLoc_Location::*)(const TopLoc_Location &) const) &TopLoc_Location::Multiplied, "Returns <me> * <Other>, the elementary datums are concatenated.", py::arg("Other"));
cls_TopLoc_Location.def("__mul__", (TopLoc_Location (TopLoc_Location::*)(const TopLoc_Location &) const) &TopLoc_Location::operator*, py::is_operator(), "None", py::arg("Other"));
cls_TopLoc_Location.def("Divided", (TopLoc_Location (TopLoc_Location::*)(const TopLoc_Location &) const) &TopLoc_Location::Divided, "Returns <me> / <Other>.", py::arg("Other"));
cls_TopLoc_Location.def("__truediv__", (TopLoc_Location (TopLoc_Location::*)(const TopLoc_Location &) const) &TopLoc_Location::operator/, py::is_operator(), "None", py::arg("Other"));
cls_TopLoc_Location.def("Predivided", (TopLoc_Location (TopLoc_Location::*)(const TopLoc_Location &) const) &TopLoc_Location::Predivided, "Returns <Other>.Inverted() * <me>.", py::arg("Other"));
cls_TopLoc_Location.def("Powered", (TopLoc_Location (TopLoc_Location::*)(const Standard_Integer) const) &TopLoc_Location::Powered, "Returns me at the power <pwr>. If <pwr> is zero returns Identity. <pwr> can be lower than zero (usual meaning for powers).", py::arg("pwr"));
cls_TopLoc_Location.def("HashCode", (Standard_Integer (TopLoc_Location::*)(Standard_Integer) const) &TopLoc_Location::HashCode, "Returns a hashed value for this local coordinate system. This value is used, with map tables, to store and retrieve the object easily, and is in the range [1, theUpperBound].", py::arg("theUpperBound"));
cls_TopLoc_Location.def("IsEqual", (Standard_Boolean (TopLoc_Location::*)(const TopLoc_Location &) const) &TopLoc_Location::IsEqual, "Returns true if this location and the location Other have the same elementary data, i.e. contain the same series of TopLoc_Datum3D and respective powers. This method is an alias for operator ==.", py::arg("Other"));
cls_TopLoc_Location.def("__eq__", (Standard_Boolean (TopLoc_Location::*)(const TopLoc_Location &) const) &TopLoc_Location::operator==, py::is_operator(), "None", py::arg("Other"));
cls_TopLoc_Location.def("IsDifferent", (Standard_Boolean (TopLoc_Location::*)(const TopLoc_Location &) const) &TopLoc_Location::IsDifferent, "Returns true if this location and the location Other do not have the same elementary data, i.e. do not contain the same series of TopLoc_Datum3D and respective powers. This method is an alias for operator !=.", py::arg("Other"));
cls_TopLoc_Location.def("__ne__", (Standard_Boolean (TopLoc_Location::*)(const TopLoc_Location &) const) &TopLoc_Location::operator!=, py::is_operator(), "None", py::arg("Other"));
cls_TopLoc_Location.def("DumpJson", [](TopLoc_Location &self, Standard_OStream & a0) -> void { return self.DumpJson(a0); });
cls_TopLoc_Location.def("DumpJson", (void (TopLoc_Location::*)(Standard_OStream &, const Standard_Integer) const) &TopLoc_Location::DumpJson, "Dumps the content of me into the stream", py::arg("theOStream"), py::arg("theDepth"));
cls_TopLoc_Location.def("ShallowDump", (void (TopLoc_Location::*)(Standard_OStream &) const) &TopLoc_Location::ShallowDump, "Prints the contents of <me> on the stream .", py::arg("S"));

// CLASS: TOPLOC_ITEMLOCATION
py::class_<TopLoc_ItemLocation> cls_TopLoc_ItemLocation(mod, "TopLoc_ItemLocation", "An ItemLocation is an elementary coordinate system in a Location.");

// Constructors
cls_TopLoc_ItemLocation.def(py::init<const opencascade::handle<TopLoc_Datum3D> &, const Standard_Integer>(), py::arg("D"), py::arg("P"));

// Methods
// cls_TopLoc_ItemLocation.def_static("operator new_", (void * (*)(size_t)) &TopLoc_ItemLocation::operator new, "None", py::arg("theSize"));
// cls_TopLoc_ItemLocation.def_static("operator delete_", (void (*)(void *)) &TopLoc_ItemLocation::operator delete, "None", py::arg("theAddress"));
// cls_TopLoc_ItemLocation.def_static("operator new[]_", (void * (*)(size_t)) &TopLoc_ItemLocation::operator new[], "None", py::arg("theSize"));
// cls_TopLoc_ItemLocation.def_static("operator delete[]_", (void (*)(void *)) &TopLoc_ItemLocation::operator delete[], "None", py::arg("theAddress"));
// cls_TopLoc_ItemLocation.def_static("operator new_", (void * (*)(size_t, void *)) &TopLoc_ItemLocation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopLoc_ItemLocation.def_static("operator delete_", (void (*)(void *, void *)) &TopLoc_ItemLocation::operator delete, "None", py::arg(""), py::arg(""));
cls_TopLoc_ItemLocation.def("DumpJson", [](TopLoc_ItemLocation &self, Standard_OStream & a0) -> void { return self.DumpJson(a0); });
cls_TopLoc_ItemLocation.def("DumpJson", (void (TopLoc_ItemLocation::*)(Standard_OStream &, const Standard_Integer) const) &TopLoc_ItemLocation::DumpJson, "Dumps the content of me into the stream", py::arg("theOStream"), py::arg("theDepth"));

// TYPEDEF: TOPLOC_MAPLOCATIONHASHER
bind_NCollection_DefaultHasher<TopLoc_Location>(mod, "TopLoc_MapLocationHasher", py::module_local(false));

// TYPEDEF: TOPLOC_INDEXEDMAPOFLOCATION
bind_NCollection_IndexedMap<TopLoc_Location, NCollection_DefaultHasher<TopLoc_Location> >(mod, "TopLoc_IndexedMapOfLocation", py::module_local(false));

// CLASS: TOPLOC_DATUM3D
py::class_<TopLoc_Datum3D, opencascade::handle<TopLoc_Datum3D>, Standard_Transient> cls_TopLoc_Datum3D(mod, "TopLoc_Datum3D", "Describes a coordinate transformation, i.e. a change to an elementary 3D coordinate system, or position in 3D space. A Datum3D is always described relative to the default datum. The default datum is described relative to itself: its origin is (0,0,0), and its axes are (1,0,0) (0,1,0) (0,0,1).");

// Constructors
cls_TopLoc_Datum3D.def(py::init<>());
cls_TopLoc_Datum3D.def(py::init<const gp_Trsf &>(), py::arg("T"));

// Methods
cls_TopLoc_Datum3D.def("Transformation", (const gp_Trsf & (TopLoc_Datum3D::*)() const) &TopLoc_Datum3D::Transformation, "Returns a gp_Trsf which, when applied to this datum, produces the default datum.");
cls_TopLoc_Datum3D.def("DumpJson", [](TopLoc_Datum3D &self, Standard_OStream & a0) -> void { return self.DumpJson(a0); });
cls_TopLoc_Datum3D.def("DumpJson", (void (TopLoc_Datum3D::*)(Standard_OStream &, const Standard_Integer) const) &TopLoc_Datum3D::DumpJson, "Dumps the content of me into the stream", py::arg("theOStream"), py::arg("theDepth"));
cls_TopLoc_Datum3D.def("ShallowDump", (void (TopLoc_Datum3D::*)(Standard_OStream &) const) &TopLoc_Datum3D::ShallowDump, "Writes the contents of this Datum3D to the stream S.", py::arg("S"));
cls_TopLoc_Datum3D.def_static("get_type_name_", (const char * (*)()) &TopLoc_Datum3D::get_type_name, "None");
cls_TopLoc_Datum3D.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopLoc_Datum3D::get_type_descriptor, "None");
cls_TopLoc_Datum3D.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopLoc_Datum3D::*)() const) &TopLoc_Datum3D::DynamicType, "None");

// TYPEDEF: TOPLOC_MAPOFLOCATION
bind_NCollection_Map<TopLoc_Location, NCollection_DefaultHasher<TopLoc_Location> >(mod, "TopLoc_MapOfLocation", py::module_local(false));

// TYPEDEF: TOPLOC_MAPITERATOROFMAPOFLOCATION

// CLASS: TOPLOC_SLISTNODEOFITEMLOCATION
py::class_<TopLoc_SListNodeOfItemLocation, opencascade::handle<TopLoc_SListNodeOfItemLocation>, Standard_Transient> cls_TopLoc_SListNodeOfItemLocation(mod, "TopLoc_SListNodeOfItemLocation", "None");

// Constructors
cls_TopLoc_SListNodeOfItemLocation.def(py::init<const TopLoc_ItemLocation &, const TopLoc_SListOfItemLocation &>(), py::arg("I"), py::arg("aTail"));

// Methods
cls_TopLoc_SListNodeOfItemLocation.def("Tail", (TopLoc_SListOfItemLocation & (TopLoc_SListNodeOfItemLocation::*)() const) &TopLoc_SListNodeOfItemLocation::Tail, "None");
cls_TopLoc_SListNodeOfItemLocation.def("Value", (TopLoc_ItemLocation & (TopLoc_SListNodeOfItemLocation::*)() const) &TopLoc_SListNodeOfItemLocation::Value, "None");
cls_TopLoc_SListNodeOfItemLocation.def_static("get_type_name_", (const char * (*)()) &TopLoc_SListNodeOfItemLocation::get_type_name, "None");
cls_TopLoc_SListNodeOfItemLocation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopLoc_SListNodeOfItemLocation::get_type_descriptor, "None");
cls_TopLoc_SListNodeOfItemLocation.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopLoc_SListNodeOfItemLocation::*)() const) &TopLoc_SListNodeOfItemLocation::DynamicType, "None");


}
