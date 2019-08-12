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

void bind_Law_Function(py::module &);
void bind_Law_Laws(py::module &);
void bind_Law_ListIteratorOfLaws(py::module &);
void bind_Law(py::module &);
void bind_Law_BSpFunc(py::module &);
void bind_Law_BSpline(py::module &);
void bind_Law_BSplineKnotSplitting(py::module &);
void bind_Law_Composite(py::module &);
void bind_Law_Constant(py::module &);
void bind_Law_Interpol(py::module &);
void bind_Law_Interpolate(py::module &);
void bind_Law_Linear(py::module &);
void bind_Law_S(py::module &);

PYBIND11_MODULE(Law, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.Adaptor3d");
py::module::import("OCCT.TColgp");

bind_Law_Function(mod);
bind_Law_Laws(mod);
bind_Law_ListIteratorOfLaws(mod);
bind_Law(mod);
bind_Law_BSpFunc(mod);
bind_Law_BSpline(mod);
bind_Law_BSplineKnotSplitting(mod);
bind_Law_Composite(mod);
bind_Law_Constant(mod);
bind_Law_Interpol(mod);
bind_Law_Interpolate(mod);
bind_Law_Linear(mod);
bind_Law_S(mod);

}
