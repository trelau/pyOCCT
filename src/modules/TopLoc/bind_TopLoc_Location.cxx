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
#include <gp_Trsf.hxx>
#include <Standard_Handle.hxx>
#include <TopLoc_Datum3D.hxx>
#include <Standard_TypeDef.hxx>
#include <TopLoc_Location.hxx>
#include <Standard_OStream.hxx>
#include <TopLoc_SListOfItemLocation.hxx>

void bind_TopLoc_Location(py::module &mod){

py::class_<TopLoc_Location, std::unique_ptr<TopLoc_Location, Deleter<TopLoc_Location>>> cls_TopLoc_Location(mod, "TopLoc_Location", "A Location is a composite transition. It comprises a series of elementary reference coordinates, i.e. objects of type TopLoc_Datum3D, and the powers to which these objects are raised.");

// Constructors
cls_TopLoc_Location.def(py::init<>());
cls_TopLoc_Location.def(py::init<const gp_Trsf &>(), py::arg("T"));
cls_TopLoc_Location.def(py::init<const opencascade::handle<TopLoc_Datum3D> &>(), py::arg("D"));

// Fields

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
cls_TopLoc_Location.def("HashCode", (Standard_Integer (TopLoc_Location::*)(const Standard_Integer) const) &TopLoc_Location::HashCode, "Returns a hashed value for this local coordinate system. This value is used, with map tables, to store and retrieve the object easily, and is in the range [ 1..Upper ].", py::arg("Upper"));
cls_TopLoc_Location.def("IsEqual", (Standard_Boolean (TopLoc_Location::*)(const TopLoc_Location &) const) &TopLoc_Location::IsEqual, "Returns true if this location and the location Other have the same elementary data, i.e. contain the same series of TopLoc_Datum3D and respective powers. This method is an alias for operator ==.", py::arg("Other"));
cls_TopLoc_Location.def("__eq__", (Standard_Boolean (TopLoc_Location::*)(const TopLoc_Location &) const) &TopLoc_Location::operator==, py::is_operator(), "None", py::arg("Other"));
cls_TopLoc_Location.def("IsDifferent", (Standard_Boolean (TopLoc_Location::*)(const TopLoc_Location &) const) &TopLoc_Location::IsDifferent, "Returns true if this location and the location Other do not have the same elementary data, i.e. do not contain the same series of TopLoc_Datum3D and respective powers. This method is an alias for operator !=.", py::arg("Other"));
cls_TopLoc_Location.def("__ne__", (Standard_Boolean (TopLoc_Location::*)(const TopLoc_Location &) const) &TopLoc_Location::operator!=, py::is_operator(), "None", py::arg("Other"));
cls_TopLoc_Location.def("ShallowDump", (void (TopLoc_Location::*)(Standard_OStream &) const) &TopLoc_Location::ShallowDump, "Prints the contents of <me> on the stream .", py::arg("S"));

// Enums

}