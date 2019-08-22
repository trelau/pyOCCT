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
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <IFSelect_WorkSession.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_HSequenceOfTransient.hxx>
#include <IFSelect_Dispatch.hxx>
#include <IFSelect_Functions.hxx>

void bind_IFSelect_Functions(py::module &mod){

py::class_<IFSelect_Functions> cls_IFSelect_Functions(mod, "IFSelect_Functions", "Functions gives access to all the actions which can be commanded with the resources provided by IFSelect : especially WorkSession and various types of Selections and Dispatches");

// Constructors

// Fields

// Methods
// cls_IFSelect_Functions.def_static("operator new_", (void * (*)(size_t)) &IFSelect_Functions::operator new, "None", py::arg("theSize"));
// cls_IFSelect_Functions.def_static("operator delete_", (void (*)(void *)) &IFSelect_Functions::operator delete, "None", py::arg("theAddress"));
// cls_IFSelect_Functions.def_static("operator new[]_", (void * (*)(size_t)) &IFSelect_Functions::operator new[], "None", py::arg("theSize"));
// cls_IFSelect_Functions.def_static("operator delete[]_", (void (*)(void *)) &IFSelect_Functions::operator delete[], "None", py::arg("theAddress"));
// cls_IFSelect_Functions.def_static("operator new_", (void * (*)(size_t, void *)) &IFSelect_Functions::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IFSelect_Functions.def_static("operator delete_", (void (*)(void *, void *)) &IFSelect_Functions::operator delete, "None", py::arg(""), py::arg(""));
cls_IFSelect_Functions.def_static("GiveEntity_", [](const opencascade::handle<IFSelect_WorkSession> & a0) -> opencascade::handle<Standard_Transient> { return IFSelect_Functions::GiveEntity(a0); });
cls_IFSelect_Functions.def_static("GiveEntity_", (opencascade::handle<Standard_Transient> (*)(const opencascade::handle<IFSelect_WorkSession> &, const Standard_CString)) &IFSelect_Functions::GiveEntity, "Takes the name of an entity, either as argument, or (if <name> is empty) on keybord, and returns the entity name can be a label or a number (in alphanumeric), it is searched by NumberFromLabel from WorkSession. If <name> doesn't match en entity, a Null Handle is returned", py::arg("WS"), py::arg("name"));
cls_IFSelect_Functions.def_static("GiveEntityNumber_", [](const opencascade::handle<IFSelect_WorkSession> & a0) -> Standard_Integer { return IFSelect_Functions::GiveEntityNumber(a0); });
cls_IFSelect_Functions.def_static("GiveEntityNumber_", (Standard_Integer (*)(const opencascade::handle<IFSelect_WorkSession> &, const Standard_CString)) &IFSelect_Functions::GiveEntityNumber, "Same as GetEntity, but returns the number in the model of the entity. Returns 0 for null handle", py::arg("WS"), py::arg("name"));
cls_IFSelect_Functions.def_static("GiveList_", [](const opencascade::handle<IFSelect_WorkSession> & a0) -> opencascade::handle<TColStd_HSequenceOfTransient> { return IFSelect_Functions::GiveList(a0); });
cls_IFSelect_Functions.def_static("GiveList_", [](const opencascade::handle<IFSelect_WorkSession> & a0, const Standard_CString a1) -> opencascade::handle<TColStd_HSequenceOfTransient> { return IFSelect_Functions::GiveList(a0, a1); });
cls_IFSelect_Functions.def_static("GiveList_", (opencascade::handle<TColStd_HSequenceOfTransient> (*)(const opencascade::handle<IFSelect_WorkSession> &, const Standard_CString, const Standard_CString)) &IFSelect_Functions::GiveList, "Computes a List of entities from a WorkSession and two idents, first and second, as follows : if <first> is a Number or Label of an entity : this entity if <first> is the name of a Selection in <WS>, and <second> not defined, the standard result of this Selection if <first> is for a Selection and <second> is defined, the standard result of this selection from the list computed with <second> (an entity or a selection) If <second> is erroneous, it is ignored", py::arg("WS"), py::arg("first"), py::arg("second"));
cls_IFSelect_Functions.def_static("GiveDispatch_", [](const opencascade::handle<IFSelect_WorkSession> & a0, const Standard_CString a1) -> opencascade::handle<IFSelect_Dispatch> { return IFSelect_Functions::GiveDispatch(a0, a1); });
cls_IFSelect_Functions.def_static("GiveDispatch_", (opencascade::handle<IFSelect_Dispatch> (*)(const opencascade::handle<IFSelect_WorkSession> &, const Standard_CString, const Standard_Boolean)) &IFSelect_Functions::GiveDispatch, "Evaluates and returns a Dispatch, from data of a WorkSession if <mode> is False, searches for exact name of Dispatch in WS Else (D), allows a parameter between brackets : ex.: dispatch_name(parameter) The parameter can be: an integer for DispPerCount or DispPerFiles or the name of a Signature for DispPerSignature Returns Null Handle if not found not well evaluated", py::arg("WS"), py::arg("name"), py::arg("mode"));
cls_IFSelect_Functions.def_static("Init_", (void (*)()) &IFSelect_Functions::Init, "Defines and loads all basic functions (as ActFunc)");

// Enums

}