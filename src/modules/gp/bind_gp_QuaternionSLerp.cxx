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
#include <gp_Quaternion.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_QuaternionSLerp.hxx>

void bind_gp_QuaternionSLerp(py::module &mod){

py::class_<gp_QuaternionSLerp> cls_gp_QuaternionSLerp(mod, "gp_QuaternionSLerp", "Perform Spherical Linear Interpolation of the quaternions, return unit length quaternion.");

// Constructors
cls_gp_QuaternionSLerp.def(py::init<>());
cls_gp_QuaternionSLerp.def(py::init<const gp_Quaternion &, const gp_Quaternion &>(), py::arg("theQStart"), py::arg("theQEnd"));

// Fields

// Methods
cls_gp_QuaternionSLerp.def_static("Interpolate_", (gp_Quaternion (*)(const gp_Quaternion &, const gp_Quaternion &, Standard_Real)) &gp_QuaternionSLerp::Interpolate, "Compute interpolated quaternion between two quaternions.", py::arg("theQStart"), py::arg("theQEnd"), py::arg("theT"));
cls_gp_QuaternionSLerp.def("Init", (void (gp_QuaternionSLerp::*)(const gp_Quaternion &, const gp_Quaternion &)) &gp_QuaternionSLerp::Init, "Initialize the tool with Start and End values.", py::arg("theQStart"), py::arg("theQEnd"));
cls_gp_QuaternionSLerp.def("InitFromUnit", (void (gp_QuaternionSLerp::*)(const gp_Quaternion &, const gp_Quaternion &)) &gp_QuaternionSLerp::InitFromUnit, "Initialize the tool with Start and End unit quaternions.", py::arg("theQStart"), py::arg("theQEnd"));
cls_gp_QuaternionSLerp.def("Interpolate", (void (gp_QuaternionSLerp::*)(Standard_Real, gp_Quaternion &) const) &gp_QuaternionSLerp::Interpolate, "Set interpolated quaternion for theT position (from 0.0 to 1.0)", py::arg("theT"), py::arg("theResultQ"));

// Enums

}