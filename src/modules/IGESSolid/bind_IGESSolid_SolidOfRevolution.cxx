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
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <IGESSolid_SolidOfRevolution.hxx>
#include <Standard_Type.hxx>

void bind_IGESSolid_SolidOfRevolution(py::module &mod){

py::class_<IGESSolid_SolidOfRevolution, opencascade::handle<IGESSolid_SolidOfRevolution>, IGESData_IGESEntity> cls_IGESSolid_SolidOfRevolution(mod, "IGESSolid_SolidOfRevolution", "defines SolidOfRevolution, Type <162> Form Number <0,1> in package IGESSolid This entity is defined by revolving the area determined by a planar curve about a specified axis through a given fraction of full rotation.");

// Constructors
cls_IGESSolid_SolidOfRevolution.def(py::init<>());

// Fields

// Methods
cls_IGESSolid_SolidOfRevolution.def("Init", (void (IGESSolid_SolidOfRevolution::*)(const opencascade::handle<IGESData_IGESEntity> &, const Standard_Real, const gp_XYZ &, const gp_XYZ &)) &IGESSolid_SolidOfRevolution::Init, "This method is used to set the fields of the class SolidOfRevolution - aCurve : the curve entity that is to be revolved - aFract : the fraction of full rotation (default 1.0) - aAxisPnt : the point on the axis - aDirection : the direction of the axis", py::arg("aCurve"), py::arg("aFract"), py::arg("aAxisPnt"), py::arg("aDirection"));
cls_IGESSolid_SolidOfRevolution.def("SetClosedToAxis", (void (IGESSolid_SolidOfRevolution::*)(const Standard_Boolean)) &IGESSolid_SolidOfRevolution::SetClosedToAxis, "Sets the Curve to be by default, Closed to Axis (Form 0) if <mode> is True, Closed to Itself (Form 1) else", py::arg("mode"));
cls_IGESSolid_SolidOfRevolution.def("IsClosedToAxis", (Standard_Boolean (IGESSolid_SolidOfRevolution::*)() const) &IGESSolid_SolidOfRevolution::IsClosedToAxis, "Returns True if Form Number = 0 if Form no is 0, then the curve is closed to axis if 1, the curve is closed to itself.");
cls_IGESSolid_SolidOfRevolution.def("Curve", (opencascade::handle<IGESData_IGESEntity> (IGESSolid_SolidOfRevolution::*)() const) &IGESSolid_SolidOfRevolution::Curve, "returns the curve entity that is to be revolved");
cls_IGESSolid_SolidOfRevolution.def("Fraction", (Standard_Real (IGESSolid_SolidOfRevolution::*)() const) &IGESSolid_SolidOfRevolution::Fraction, "returns the fraction of full rotation that the curve is to be rotated");
cls_IGESSolid_SolidOfRevolution.def("AxisPoint", (gp_Pnt (IGESSolid_SolidOfRevolution::*)() const) &IGESSolid_SolidOfRevolution::AxisPoint, "returns the point on the axis");
cls_IGESSolid_SolidOfRevolution.def("TransformedAxisPoint", (gp_Pnt (IGESSolid_SolidOfRevolution::*)() const) &IGESSolid_SolidOfRevolution::TransformedAxisPoint, "returns the point on the axis after applying Trans.Matrix");
cls_IGESSolid_SolidOfRevolution.def("Axis", (gp_Dir (IGESSolid_SolidOfRevolution::*)() const) &IGESSolid_SolidOfRevolution::Axis, "returns the direction of the axis");
cls_IGESSolid_SolidOfRevolution.def("TransformedAxis", (gp_Dir (IGESSolid_SolidOfRevolution::*)() const) &IGESSolid_SolidOfRevolution::TransformedAxis, "returns the direction of the axis after applying TransformationMatrix");
cls_IGESSolid_SolidOfRevolution.def_static("get_type_name_", (const char * (*)()) &IGESSolid_SolidOfRevolution::get_type_name, "None");
cls_IGESSolid_SolidOfRevolution.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSolid_SolidOfRevolution::get_type_descriptor, "None");
cls_IGESSolid_SolidOfRevolution.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSolid_SolidOfRevolution::*)() const) &IGESSolid_SolidOfRevolution::DynamicType, "None");

// Enums

}