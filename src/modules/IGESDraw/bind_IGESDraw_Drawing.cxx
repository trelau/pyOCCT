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
#include <IGESDraw_HArray1OfViewKindEntity.hxx>
#include <TColgp_HArray1OfXY.hxx>
#include <IGESData_HArray1OfIGESEntity.hxx>
#include <Standard_TypeDef.hxx>
#include <IGESData_ViewKindEntity.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_XY.hxx>
#include <gp_XYZ.hxx>
#include <IGESDraw_Drawing.hxx>
#include <Standard_Type.hxx>

void bind_IGESDraw_Drawing(py::module &mod){

py::class_<IGESDraw_Drawing, opencascade::handle<IGESDraw_Drawing>, IGESData_IGESEntity> cls_IGESDraw_Drawing(mod, "IGESDraw_Drawing", "defines IGESDrawing, Type <404> Form <0> in package IGESDraw");

// Constructors
cls_IGESDraw_Drawing.def(py::init<>());

// Fields

// Methods
cls_IGESDraw_Drawing.def("Init", (void (IGESDraw_Drawing::*)(const opencascade::handle<IGESDraw_HArray1OfViewKindEntity> &, const opencascade::handle<TColgp_HArray1OfXY> &, const opencascade::handle<IGESData_HArray1OfIGESEntity> &)) &IGESDraw_Drawing::Init, "This method is used to set the fields of the class Drawing - allViews : Pointers to DEs of View entities - allViewOrigins : Origin coordinates of transformed Views - allAnnotations : Pointers to DEs of Annotation entities raises exception if Lengths of allViews and allViewOrigins are not same.", py::arg("allViews"), py::arg("allViewOrigins"), py::arg("allAnnotations"));
cls_IGESDraw_Drawing.def("NbViews", (Standard_Integer (IGESDraw_Drawing::*)() const) &IGESDraw_Drawing::NbViews, "returns the number of view pointers in <me>");
cls_IGESDraw_Drawing.def("ViewItem", (opencascade::handle<IGESData_ViewKindEntity> (IGESDraw_Drawing::*)(const Standard_Integer) const) &IGESDraw_Drawing::ViewItem, "returns the ViewKindEntity indicated by ViewIndex raises an exception if ViewIndex <= 0 or ViewIndex > NbViews().", py::arg("ViewIndex"));
cls_IGESDraw_Drawing.def("ViewOrigin", (gp_Pnt2d (IGESDraw_Drawing::*)(const Standard_Integer) const) &IGESDraw_Drawing::ViewOrigin, "returns the Drawing space coordinates of the origin of the Transformed view indicated by TViewIndex raises an exception if TViewIndex <= 0 or TViewIndex > NbViews().", py::arg("TViewIndex"));
cls_IGESDraw_Drawing.def("NbAnnotations", (Standard_Integer (IGESDraw_Drawing::*)() const) &IGESDraw_Drawing::NbAnnotations, "returns the number of Annotation entities in <me>");
cls_IGESDraw_Drawing.def("Annotation", (opencascade::handle<IGESData_IGESEntity> (IGESDraw_Drawing::*)(const Standard_Integer) const) &IGESDraw_Drawing::Annotation, "returns the Annotation entity in this Drawing, indicated by the AnnotationIndex raises an exception if AnnotationIndex <= 0 or AnnotationIndex > NbAnnotations().", py::arg("AnnotationIndex"));
cls_IGESDraw_Drawing.def("ViewToDrawing", (gp_XY (IGESDraw_Drawing::*)(const Standard_Integer, const gp_XYZ &) const) &IGESDraw_Drawing::ViewToDrawing, "None", py::arg("NumView"), py::arg("ViewCoords"));
cls_IGESDraw_Drawing.def("DrawingUnit", [](IGESDraw_Drawing &self, Standard_Real & value){ Standard_Boolean rv = self.DrawingUnit(value); return std::tuple<Standard_Boolean, Standard_Real &>(rv, value); }, "Returns the Drawing Unit Value if it is specified (by a specific property entity) If not specified, returns False, and val as zero : unit to consider is then the model unit in GlobalSection", py::arg("value"));
cls_IGESDraw_Drawing.def("DrawingSize", [](IGESDraw_Drawing &self, Standard_Real & X, Standard_Real & Y){ Standard_Boolean rv = self.DrawingSize(X, Y); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, X, Y); }, "Returns the Drawing Size if it is specified (by a specific property entity) If not specified, returns False, and X,Y as zero : unit to consider is then the model unit in GlobalSection", py::arg("X"), py::arg("Y"));
cls_IGESDraw_Drawing.def_static("get_type_name_", (const char * (*)()) &IGESDraw_Drawing::get_type_name, "None");
cls_IGESDraw_Drawing.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDraw_Drawing::get_type_descriptor, "None");
cls_IGESDraw_Drawing.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDraw_Drawing::*)() const) &IGESDraw_Drawing::DynamicType, "None");

// Enums

}