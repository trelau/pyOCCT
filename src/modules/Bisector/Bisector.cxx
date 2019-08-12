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

void bind_Bisector(py::module &);
void bind_Bisector_Bisec(py::module &);
void bind_Bisector_Curve(py::module &);
void bind_Bisector_BisecAna(py::module &);
void bind_Bisector_PointOnBis(py::module &);
void bind_Bisector_PolyBis(py::module &);
void bind_Bisector_BisecCC(py::module &);
void bind_Bisector_BisecPC(py::module &);
void bind_Bisector_FunctionH(py::module &);
void bind_Bisector_FunctionInter(py::module &);
void bind_Bisector_Inter(py::module &);

PYBIND11_MODULE(Bisector, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.gp");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.GccInt");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.math");
py::module::import("OCCT.IntRes2d");

bind_Bisector(mod);
bind_Bisector_Bisec(mod);
bind_Bisector_Curve(mod);
bind_Bisector_BisecAna(mod);
bind_Bisector_PointOnBis(mod);
bind_Bisector_PolyBis(mod);
bind_Bisector_BisecCC(mod);
bind_Bisector_BisecPC(mod);
bind_Bisector_FunctionH(mod);
bind_Bisector_FunctionInter(mod);
bind_Bisector_Inter(mod);

}
