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

void bind_CPnts_RealFunction(py::module &);
void bind_CPnts_MyGaussFunction(py::module &);
void bind_CPnts_MyRootFunction(py::module &);
void bind_CPnts_AbscissaPoint(py::module &);
void bind_CPnts_UniformDeflection(py::module &);

PYBIND11_MODULE(CPnts, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.math");
py::module::import("OCCT.Adaptor3d");
py::module::import("OCCT.Adaptor2d");
py::module::import("OCCT.gp");

bind_CPnts_RealFunction(mod);
bind_CPnts_MyGaussFunction(mod);
bind_CPnts_MyRootFunction(mod);
bind_CPnts_AbscissaPoint(mod);
bind_CPnts_UniformDeflection(mod);

}
