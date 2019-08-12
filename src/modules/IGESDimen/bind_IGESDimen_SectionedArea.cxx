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
#include <Standard_Handle.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_XYZ.hxx>
#include <IGESData_HArray1OfIGESEntity.hxx>
#include <gp_Pnt.hxx>
#include <IGESDimen_SectionedArea.hxx>
#include <Standard_Type.hxx>

void bind_IGESDimen_SectionedArea(py::module &mod){

py::class_<IGESDimen_SectionedArea, opencascade::handle<IGESDimen_SectionedArea>, IGESData_IGESEntity> cls_IGESDimen_SectionedArea(mod, "IGESDimen_SectionedArea", "defines IGES Sectioned Area, Type <230> Form <0>, in package IGESDimen A sectioned area is a portion of a design which is to be filled with a pattern of lines. Ordinarily, this entity is used to reveal or expose shape or material characteri- stics defined by other entities. It consists of a pointer to an exterior definition curve, a specification of the pattern of lines, the coordinates of a point on a pattern line, the distance between the pattern lines, the angle between the pattern lines and the X-axis of definition space, and the specification of any enclosed definition curves (commonly known as islands).");

// Constructors
cls_IGESDimen_SectionedArea.def(py::init<>());

// Fields

// Methods
cls_IGESDimen_SectionedArea.def("Init", (void (IGESDimen_SectionedArea::*)(const opencascade::handle<IGESData_IGESEntity> &, const Standard_Integer, const gp_XYZ &, const Standard_Real, const Standard_Real, const opencascade::handle<IGESData_HArray1OfIGESEntity> &)) &IGESDimen_SectionedArea::Init, "None", py::arg("aCurve"), py::arg("aPattern"), py::arg("aPoint"), py::arg("aDistance"), py::arg("anAngle"), py::arg("someIslands"));
cls_IGESDimen_SectionedArea.def("SetInverted", (void (IGESDimen_SectionedArea::*)(const Standard_Boolean)) &IGESDimen_SectionedArea::SetInverted, "Sets the cross hatches to be inverted or not, according value of <mode> (corresponds to FormNumber)", py::arg("mode"));
cls_IGESDimen_SectionedArea.def("IsInverted", (Standard_Boolean (IGESDimen_SectionedArea::*)() const) &IGESDimen_SectionedArea::IsInverted, "Returns True if cross hatches as Inverted, else they are Standard (Inverted : Form=1, Standard : Form=0)");
cls_IGESDimen_SectionedArea.def("ExteriorCurve", (opencascade::handle<IGESData_IGESEntity> (IGESDimen_SectionedArea::*)() const) &IGESDimen_SectionedArea::ExteriorCurve, "returns the exterior definition curve");
cls_IGESDimen_SectionedArea.def("Pattern", (Standard_Integer (IGESDimen_SectionedArea::*)() const) &IGESDimen_SectionedArea::Pattern, "returns fill pattern code");
cls_IGESDimen_SectionedArea.def("PassingPoint", (gp_Pnt (IGESDimen_SectionedArea::*)() const) &IGESDimen_SectionedArea::PassingPoint, "returns point thru which line should pass");
cls_IGESDimen_SectionedArea.def("TransformedPassingPoint", (gp_Pnt (IGESDimen_SectionedArea::*)() const) &IGESDimen_SectionedArea::TransformedPassingPoint, "returns point thru which line should pass after Transformation");
cls_IGESDimen_SectionedArea.def("ZDepth", (Standard_Real (IGESDimen_SectionedArea::*)() const) &IGESDimen_SectionedArea::ZDepth, "returns the Z depth");
cls_IGESDimen_SectionedArea.def("Distance", (Standard_Real (IGESDimen_SectionedArea::*)() const) &IGESDimen_SectionedArea::Distance, "returns the normal distance between lines");
cls_IGESDimen_SectionedArea.def("Angle", (Standard_Real (IGESDimen_SectionedArea::*)() const) &IGESDimen_SectionedArea::Angle, "returns the angle of lines with XT axis");
cls_IGESDimen_SectionedArea.def("NbIslands", (Standard_Integer (IGESDimen_SectionedArea::*)() const) &IGESDimen_SectionedArea::NbIslands, "returns the number of island curves");
cls_IGESDimen_SectionedArea.def("IslandCurve", (opencascade::handle<IGESData_IGESEntity> (IGESDimen_SectionedArea::*)(const Standard_Integer) const) &IGESDimen_SectionedArea::IslandCurve, "returns the interior definition curves, returns Null Handle exception raised if Index <= 0 or Index > NbIslands()", py::arg("Index"));
cls_IGESDimen_SectionedArea.def_static("get_type_name_", (const char * (*)()) &IGESDimen_SectionedArea::get_type_name, "None");
cls_IGESDimen_SectionedArea.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDimen_SectionedArea::get_type_descriptor, "None");
cls_IGESDimen_SectionedArea.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDimen_SectionedArea::*)() const) &IGESDimen_SectionedArea::DynamicType, "None");

// Enums

}