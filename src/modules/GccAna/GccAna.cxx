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

void bind_GccAna_Circ2d2TanOn(py::module &);
void bind_GccAna_Circ2d2TanRad(py::module &);
void bind_GccAna_Circ2d3Tan(py::module &);
void bind_GccAna_Circ2dBisec(py::module &);
void bind_GccAna_Circ2dTanCen(py::module &);
void bind_GccAna_Circ2dTanOnRad(py::module &);
void bind_GccAna_CircLin2dBisec(py::module &);
void bind_GccAna_CircPnt2dBisec(py::module &);
void bind_GccAna_Lin2d2Tan(py::module &);
void bind_GccAna_Lin2dBisec(py::module &);
void bind_GccAna_Lin2dTanObl(py::module &);
void bind_GccAna_Lin2dTanPar(py::module &);
void bind_GccAna_Lin2dTanPer(py::module &);
void bind_GccAna_LinPnt2dBisec(py::module &);
void bind_GccAna_NoSolution(py::module &);
void bind_GccAna_Pnt2dBisec(py::module &);

PYBIND11_MODULE(GccAna, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.GccEnt");
py::module::import("OCCT.gp");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.GccInt");

bind_GccAna_Circ2d2TanOn(mod);
bind_GccAna_Circ2d2TanRad(mod);
bind_GccAna_Circ2d3Tan(mod);
bind_GccAna_Circ2dBisec(mod);
bind_GccAna_Circ2dTanCen(mod);
bind_GccAna_Circ2dTanOnRad(mod);
bind_GccAna_CircLin2dBisec(mod);
bind_GccAna_CircPnt2dBisec(mod);
bind_GccAna_Lin2d2Tan(mod);
bind_GccAna_Lin2dBisec(mod);
bind_GccAna_Lin2dTanObl(mod);
bind_GccAna_Lin2dTanPar(mod);
bind_GccAna_Lin2dTanPer(mod);
bind_GccAna_LinPnt2dBisec(mod);
bind_GccAna_NoSolution(mod);
bind_GccAna_Pnt2dBisec(mod);

}
