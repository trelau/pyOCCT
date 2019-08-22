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
#include <gp_QuaternionNLerp.hxx>

void bind_gp_QuaternionNLerp(py::module &mod){

py::class_<gp_QuaternionNLerp> cls_gp_QuaternionNLerp(mod, "gp_QuaternionNLerp", "Class perform linear interpolation (approximate rotation interpolation), result quaternion nonunit, its length lay between. sqrt(2)/2 and 1.0");

// Constructors
cls_gp_QuaternionNLerp.def(py::init<>());
cls_gp_QuaternionNLerp.def(py::init<const gp_Quaternion &, const gp_Quaternion &>(), py::arg("theQStart"), py::arg("theQEnd"));

// Fields

// Methods
cls_gp_QuaternionNLerp.def_static("Interpolate_", (gp_Quaternion (*)(const gp_Quaternion &, const gp_Quaternion &, Standard_Real)) &gp_QuaternionNLerp::Interpolate, "Compute interpolated quaternion between two quaternions.", py::arg("theQStart"), py::arg("theQEnd"), py::arg("theT"));
cls_gp_QuaternionNLerp.def("Init", (void (gp_QuaternionNLerp::*)(const gp_Quaternion &, const gp_Quaternion &)) &gp_QuaternionNLerp::Init, "Initialize the tool with Start and End values.", py::arg("theQStart"), py::arg("theQEnd"));
cls_gp_QuaternionNLerp.def("InitFromUnit", (void (gp_QuaternionNLerp::*)(const gp_Quaternion &, const gp_Quaternion &)) &gp_QuaternionNLerp::InitFromUnit, "Initialize the tool with Start and End unit quaternions.", py::arg("theQStart"), py::arg("theQEnd"));
cls_gp_QuaternionNLerp.def("Interpolate", (void (gp_QuaternionNLerp::*)(Standard_Real, gp_Quaternion &) const) &gp_QuaternionNLerp::Interpolate, "Set interpolated quaternion for theT position (from 0.0 to 1.0)", py::arg("theT"), py::arg("theResultQ"));

// Enums

}