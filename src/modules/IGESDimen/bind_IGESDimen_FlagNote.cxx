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
#include <IGESData_IGESEntity.hxx>
#include <gp_XYZ.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <IGESDimen_GeneralNote.hxx>
#include <IGESDimen_HArray1OfLeaderArrow.hxx>
#include <gp_Pnt.hxx>
#include <IGESDimen_LeaderArrow.hxx>
#include <IGESDimen_FlagNote.hxx>
#include <Standard_Type.hxx>

void bind_IGESDimen_FlagNote(py::module &mod){

py::class_<IGESDimen_FlagNote, opencascade::handle<IGESDimen_FlagNote>, IGESData_IGESEntity> cls_IGESDimen_FlagNote(mod, "IGESDimen_FlagNote", "defines FlagNote, Type <208> Form <0> in package IGESDimen Is label information formatted in different ways");

// Constructors
cls_IGESDimen_FlagNote.def(py::init<>());

// Fields

// Methods
cls_IGESDimen_FlagNote.def("Init", (void (IGESDimen_FlagNote::*)(const gp_XYZ &, const Standard_Real, const opencascade::handle<IGESDimen_GeneralNote> &, const opencascade::handle<IGESDimen_HArray1OfLeaderArrow> &)) &IGESDimen_FlagNote::Init, "This method is used to set the fields of the class FlagNote - leftCorner : Lower left corner of the Flag - anAngle : Rotation angle in radians - aNote : General Note Entity - someLeaders : Leader Entities", py::arg("leftCorner"), py::arg("anAngle"), py::arg("aNote"), py::arg("someLeaders"));
cls_IGESDimen_FlagNote.def("LowerLeftCorner", (gp_Pnt (IGESDimen_FlagNote::*)() const) &IGESDimen_FlagNote::LowerLeftCorner, "returns Lower Left coordinate of Flag as Pnt from package gp");
cls_IGESDimen_FlagNote.def("TransformedLowerLeftCorner", (gp_Pnt (IGESDimen_FlagNote::*)() const) &IGESDimen_FlagNote::TransformedLowerLeftCorner, "returns Lower Left coordinate of Flag as Pnt from package gp after Transformation.");
cls_IGESDimen_FlagNote.def("Angle", (Standard_Real (IGESDimen_FlagNote::*)() const) &IGESDimen_FlagNote::Angle, "returns Rotation angle in radians");
cls_IGESDimen_FlagNote.def("Note", (opencascade::handle<IGESDimen_GeneralNote> (IGESDimen_FlagNote::*)() const) &IGESDimen_FlagNote::Note, "returns General Note Entity");
cls_IGESDimen_FlagNote.def("NbLeaders", (Standard_Integer (IGESDimen_FlagNote::*)() const) &IGESDimen_FlagNote::NbLeaders, "returns number of Arrows (Leaders) or zero");
cls_IGESDimen_FlagNote.def("Leader", (opencascade::handle<IGESDimen_LeaderArrow> (IGESDimen_FlagNote::*)(const Standard_Integer) const) &IGESDimen_FlagNote::Leader, "returns Leader Entity raises exception if Index <= 0 or Index > NbLeaders()", py::arg("Index"));
cls_IGESDimen_FlagNote.def("Height", (Standard_Real (IGESDimen_FlagNote::*)() const) &IGESDimen_FlagNote::Height, "returns Height computed by the formula : Height = 2 * CH where CH is from theNote");
cls_IGESDimen_FlagNote.def("CharacterHeight", (Standard_Real (IGESDimen_FlagNote::*)() const) &IGESDimen_FlagNote::CharacterHeight, "returns the Character Height (from General Note)");
cls_IGESDimen_FlagNote.def("Length", (Standard_Real (IGESDimen_FlagNote::*)() const) &IGESDimen_FlagNote::Length, "returns Length computed by the formula : Length = TW + 0.4*CH where CH is from theNote and TW is from theNote");
cls_IGESDimen_FlagNote.def("TextWidth", (Standard_Real (IGESDimen_FlagNote::*)() const) &IGESDimen_FlagNote::TextWidth, "returns the Text Width (from General Note)");
cls_IGESDimen_FlagNote.def("TipLength", (Standard_Real (IGESDimen_FlagNote::*)() const) &IGESDimen_FlagNote::TipLength, "returns TipLength computed by the formula : TipLength = 0.5 * H / tan 35(deg) where H is Height()");
cls_IGESDimen_FlagNote.def_static("get_type_name_", (const char * (*)()) &IGESDimen_FlagNote::get_type_name, "None");
cls_IGESDimen_FlagNote.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDimen_FlagNote::get_type_descriptor, "None");
cls_IGESDimen_FlagNote.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDimen_FlagNote::*)() const) &IGESDimen_FlagNote::DynamicType, "None");

// Enums

}