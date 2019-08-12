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
#include <IGESToBRep_IGESBoundary.hxx>
#include <IGESToBRep_CurveAndSurface.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <IGESControl_IGESBoundary.hxx>
#include <Standard_Type.hxx>
#include <IGESData_IGESEntity.hxx>
#include <ShapeExtend_WireData.hxx>
#include <IGESData_HArray1OfIGESEntity.hxx>

void bind_IGESControl_IGESBoundary(py::module &mod){

py::class_<IGESControl_IGESBoundary, opencascade::handle<IGESControl_IGESBoundary>, IGESToBRep_IGESBoundary> cls_IGESControl_IGESBoundary(mod, "IGESControl_IGESBoundary", "Translates IGES boundary entity (types 141, 142 and 508) in Advanced Data Exchange. Redefines translation and treatment methods from inherited open class IGESToBRep_IGESBoundary.");

// Constructors
cls_IGESControl_IGESBoundary.def(py::init<>());
cls_IGESControl_IGESBoundary.def(py::init<const IGESToBRep_CurveAndSurface &>(), py::arg("CS"));

// Fields

// Methods
cls_IGESControl_IGESBoundary.def("Check", (void (IGESControl_IGESBoundary::*)(const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean)) &IGESControl_IGESBoundary::Check, "Checks result of translation of IGES boundary entities (types 141, 142 or 508). Checks consistency of 2D and 3D representations and keeps only one if they are inconsistent. Checks the closure of resulting wire and if it is not closed, checks 2D and 3D representation and updates the resulting wire to contain only closed representation.", py::arg("result"), py::arg("checkclosure"), py::arg("okCurve3d"), py::arg("okCurve2d"));
cls_IGESControl_IGESBoundary.def_static("get_type_name_", (const char * (*)()) &IGESControl_IGESBoundary::get_type_name, "None");
cls_IGESControl_IGESBoundary.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESControl_IGESBoundary::get_type_descriptor, "None");
cls_IGESControl_IGESBoundary.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESControl_IGESBoundary::*)() const) &IGESControl_IGESBoundary::DynamicType, "None");

// Enums

}