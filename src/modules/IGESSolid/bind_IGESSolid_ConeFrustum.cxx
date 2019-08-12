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
#include <Standard_TypeDef.hxx>
#include <gp_XYZ.hxx>
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <Standard_Handle.hxx>
#include <IGESSolid_ConeFrustum.hxx>
#include <Standard_Type.hxx>

void bind_IGESSolid_ConeFrustum(py::module &mod){

py::class_<IGESSolid_ConeFrustum, opencascade::handle<IGESSolid_ConeFrustum>, IGESData_IGESEntity> cls_IGESSolid_ConeFrustum(mod, "IGESSolid_ConeFrustum", "defines ConeFrustum, Type <156> Form Number <0> in package IGESSolid The Cone Frustum is defined by the center of the larger circular face of the frustum, its radius, a unit vector in the axis direction, a height in this direction and a second circular face with radius which is lesser than the first face.");

// Constructors
cls_IGESSolid_ConeFrustum.def(py::init<>());

// Fields

// Methods
cls_IGESSolid_ConeFrustum.def("Init", (void (IGESSolid_ConeFrustum::*)(const Standard_Real, const Standard_Real, const Standard_Real, const gp_XYZ &, const gp_XYZ &)) &IGESSolid_ConeFrustum::Init, "This method is used to set the fields of the class ConeFrustum - Ht : the Height of cone - R1 : Radius of the larger face - R2 : Radius of the smaller face (default 0) - Center : Center of the larger face (default (0,0,0)) - anAxis : Unit vector in axis direction (default (0,0,1))", py::arg("Ht"), py::arg("R1"), py::arg("R2"), py::arg("Center"), py::arg("anAxis"));
cls_IGESSolid_ConeFrustum.def("Height", (Standard_Real (IGESSolid_ConeFrustum::*)() const) &IGESSolid_ConeFrustum::Height, "returns the height of the cone frustum");
cls_IGESSolid_ConeFrustum.def("LargerRadius", (Standard_Real (IGESSolid_ConeFrustum::*)() const) &IGESSolid_ConeFrustum::LargerRadius, "returns the radius of the larger face of the cone frustum");
cls_IGESSolid_ConeFrustum.def("SmallerRadius", (Standard_Real (IGESSolid_ConeFrustum::*)() const) &IGESSolid_ConeFrustum::SmallerRadius, "returns the radius of the second face of the cone frustum");
cls_IGESSolid_ConeFrustum.def("FaceCenter", (gp_Pnt (IGESSolid_ConeFrustum::*)() const) &IGESSolid_ConeFrustum::FaceCenter, "returns the center of the larger face of the cone frustum");
cls_IGESSolid_ConeFrustum.def("TransformedFaceCenter", (gp_Pnt (IGESSolid_ConeFrustum::*)() const) &IGESSolid_ConeFrustum::TransformedFaceCenter, "returns the center of the larger face of the cone frustum after applying TransformationMatrix");
cls_IGESSolid_ConeFrustum.def("Axis", (gp_Dir (IGESSolid_ConeFrustum::*)() const) &IGESSolid_ConeFrustum::Axis, "returns the direction of the axis of the cone frustum");
cls_IGESSolid_ConeFrustum.def("TransformedAxis", (gp_Dir (IGESSolid_ConeFrustum::*)() const) &IGESSolid_ConeFrustum::TransformedAxis, "returns the direction of the axis of the cone frustum after applying TransformationMatrix");
cls_IGESSolid_ConeFrustum.def_static("get_type_name_", (const char * (*)()) &IGESSolid_ConeFrustum::get_type_name, "None");
cls_IGESSolid_ConeFrustum.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSolid_ConeFrustum::get_type_descriptor, "None");
cls_IGESSolid_ConeFrustum.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSolid_ConeFrustum::*)() const) &IGESSolid_ConeFrustum::DynamicType, "None");

// Enums

}