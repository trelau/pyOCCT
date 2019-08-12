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

void bind_LProp_Status(py::module &);
void bind_LProp_CIType(py::module &);
void bind_LProp_SequenceOfCIType(py::module &);
void bind_LProp_CurAndInf(py::module &);
void bind_LProp_AnalyticCurInf(py::module &);
void bind_LProp_BadContinuity(py::module &);
void bind_LProp_NotDefined(py::module &);

PYBIND11_MODULE(LProp, mod) {

py::module::import("OCCT.NCollection");
py::module::import("OCCT.Standard");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.GeomAbs");

bind_LProp_Status(mod);
bind_LProp_CIType(mod);
bind_LProp_SequenceOfCIType(mod);
bind_LProp_CurAndInf(mod);
bind_LProp_AnalyticCurInf(mod);
bind_LProp_BadContinuity(mod);
bind_LProp_NotDefined(mod);

}
