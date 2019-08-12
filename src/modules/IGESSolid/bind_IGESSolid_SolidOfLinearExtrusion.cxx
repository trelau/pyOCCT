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
#include <gp_Dir.hxx>
#include <IGESSolid_SolidOfLinearExtrusion.hxx>
#include <Standard_Type.hxx>

void bind_IGESSolid_SolidOfLinearExtrusion(py::module &mod){

py::class_<IGESSolid_SolidOfLinearExtrusion, opencascade::handle<IGESSolid_SolidOfLinearExtrusion>, IGESData_IGESEntity> cls_IGESSolid_SolidOfLinearExtrusion(mod, "IGESSolid_SolidOfLinearExtrusion", "defines SolidOfLinearExtrusion, Type <164> Form Number <0> in package IGESSolid Solid of linear extrusion is defined by translatin an area determined by a planar curve");

// Constructors
cls_IGESSolid_SolidOfLinearExtrusion.def(py::init<>());

// Fields

// Methods
cls_IGESSolid_SolidOfLinearExtrusion.def("Init", (void (IGESSolid_SolidOfLinearExtrusion::*)(const opencascade::handle<IGESData_IGESEntity> &, const Standard_Real, const gp_XYZ &)) &IGESSolid_SolidOfLinearExtrusion::Init, "This method is used to set the fields of the class SolidOfLinearExtrusion - aCurve : the planar curve that is to be translated - aLength : the length of extrusion - aDirection : the vector specifying the direction of extrusion default (0,0,1)", py::arg("aCurve"), py::arg("aLength"), py::arg("aDirection"));
cls_IGESSolid_SolidOfLinearExtrusion.def("Curve", (opencascade::handle<IGESData_IGESEntity> (IGESSolid_SolidOfLinearExtrusion::*)() const) &IGESSolid_SolidOfLinearExtrusion::Curve, "returns the planar curve that is to be translated");
cls_IGESSolid_SolidOfLinearExtrusion.def("ExtrusionLength", (Standard_Real (IGESSolid_SolidOfLinearExtrusion::*)() const) &IGESSolid_SolidOfLinearExtrusion::ExtrusionLength, "returns the Extrusion Length");
cls_IGESSolid_SolidOfLinearExtrusion.def("ExtrusionDirection", (gp_Dir (IGESSolid_SolidOfLinearExtrusion::*)() const) &IGESSolid_SolidOfLinearExtrusion::ExtrusionDirection, "returns the Extrusion direction");
cls_IGESSolid_SolidOfLinearExtrusion.def("TransformedExtrusionDirection", (gp_Dir (IGESSolid_SolidOfLinearExtrusion::*)() const) &IGESSolid_SolidOfLinearExtrusion::TransformedExtrusionDirection, "returns ExtrusionDirection after applying TransformationMatrix");
cls_IGESSolid_SolidOfLinearExtrusion.def_static("get_type_name_", (const char * (*)()) &IGESSolid_SolidOfLinearExtrusion::get_type_name, "None");
cls_IGESSolid_SolidOfLinearExtrusion.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSolid_SolidOfLinearExtrusion::get_type_descriptor, "None");
cls_IGESSolid_SolidOfLinearExtrusion.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSolid_SolidOfLinearExtrusion::*)() const) &IGESSolid_SolidOfLinearExtrusion::DynamicType, "None");

// Enums

}