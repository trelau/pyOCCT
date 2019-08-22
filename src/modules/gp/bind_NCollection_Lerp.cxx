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
#include <gp_Trsf.hxx>
#include <Precision.hxx>
#include <gp_XYZ.hxx>
#include <gp_Quaternion.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_Lerp.hxx>
#include <gp_QuaternionNLerp.hxx>
#include <gp_TrsfNLerp.hxx>

void bind_NCollection_Lerp(py::module &mod){

py::class_<NCollection_Lerp<gp_Trsf>> cls_NCollection_Lerp(mod, "gp_TrsfNLerp", "Linear interpolation tool for transformation defined by gp_Trsf.");

// Constructors
cls_NCollection_Lerp.def(py::init<>());
cls_NCollection_Lerp.def(py::init<const gp_Trsf &, const gp_Trsf &>(), py::arg("theStart"), py::arg("theEnd"));

// Fields

// Methods
cls_NCollection_Lerp.def("Init", (void (NCollection_Lerp<gp_Trsf>::*)(const gp_Trsf &, const gp_Trsf &)) &NCollection_Lerp<gp_Trsf>::Init, "Initialize values.", py::arg("theStart"), py::arg("theEnd"));
cls_NCollection_Lerp.def("Interpolate", (void (NCollection_Lerp<gp_Trsf>::*)(double, gp_Trsf &) const) &NCollection_Lerp<gp_Trsf>::Interpolate, "Compute interpolated value between two values.", py::arg("theT"), py::arg("theResult"));

// Enums

}