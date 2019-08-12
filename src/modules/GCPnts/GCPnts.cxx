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

void bind_GCPnts_AbscissaType(py::module &);
void bind_GCPnts_DeflectionType(py::module &);
void bind_GCPnts_TangentialDeflection(py::module &);
void bind_GCPnts_AbscissaPoint(py::module &);
void bind_GCPnts_DistFunction(py::module &);
void bind_GCPnts_DistFunctionMV(py::module &);
void bind_GCPnts_DistFunction2d(py::module &);
void bind_GCPnts_DistFunction2dMV(py::module &);
void bind_GCPnts_QuasiUniformAbscissa(py::module &);
void bind_GCPnts_QuasiUniformDeflection(py::module &);
void bind_GCPnts_UniformAbscissa(py::module &);
void bind_GCPnts_UniformDeflection(py::module &);

PYBIND11_MODULE(GCPnts, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.Adaptor3d");
py::module::import("OCCT.Adaptor2d");
py::module::import("OCCT.gp");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.CPnts");
py::module::import("OCCT.math");
py::module::import("OCCT.StdFail");
py::module::import("OCCT.GeomAbs");

bind_GCPnts_AbscissaType(mod);
bind_GCPnts_DeflectionType(mod);
bind_GCPnts_TangentialDeflection(mod);
bind_GCPnts_AbscissaPoint(mod);
bind_GCPnts_DistFunction(mod);
bind_GCPnts_DistFunctionMV(mod);
bind_GCPnts_DistFunction2d(mod);
bind_GCPnts_DistFunction2dMV(mod);
bind_GCPnts_QuasiUniformAbscissa(mod);
bind_GCPnts_QuasiUniformDeflection(mod);
bind_GCPnts_UniformAbscissa(mod);
bind_GCPnts_UniformDeflection(mod);

}
