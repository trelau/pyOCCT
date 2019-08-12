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

void bind_Geom2dGcc_Type3(py::module &);
void bind_Geom2dGcc_Type1(py::module &);
void bind_Geom2dGcc_Type2(py::module &);
void bind_Geom2dGcc(py::module &);
void bind_Geom2dGcc_Circ2d2TanOn(py::module &);
void bind_Geom2dGcc_Circ2d2TanOnGeo(py::module &);
void bind_Geom2dGcc_Circ2d2TanOnIter(py::module &);
void bind_Geom2dGcc_Circ2d2TanRad(py::module &);
void bind_Geom2dGcc_Circ2d2TanRadGeo(py::module &);
void bind_Geom2dGcc_Circ2d3Tan(py::module &);
void bind_Geom2dGcc_Circ2d3TanIter(py::module &);
void bind_Geom2dGcc_Circ2dTanCen(py::module &);
void bind_Geom2dGcc_Circ2dTanCenGeo(py::module &);
void bind_Geom2dGcc_Circ2dTanOnRad(py::module &);
void bind_Geom2dGcc_Circ2dTanOnRadGeo(py::module &);
void bind_Geom2dGcc_CurveTool(py::module &);
void bind_Geom2dGcc_FunctionTanCirCu(py::module &);
void bind_Geom2dGcc_FunctionTanCuCu(py::module &);
void bind_Geom2dGcc_FunctionTanCuCuCu(py::module &);
void bind_Geom2dGcc_FunctionTanCuCuOnCu(py::module &);
void bind_Geom2dGcc_FunctionTanCuPnt(py::module &);
void bind_Geom2dGcc_FunctionTanObl(py::module &);
void bind_Geom2dGcc_IsParallel(py::module &);
void bind_Geom2dGcc_Lin2d2Tan(py::module &);
void bind_Geom2dGcc_Lin2d2TanIter(py::module &);
void bind_Geom2dGcc_Lin2dTanObl(py::module &);
void bind_Geom2dGcc_Lin2dTanOblIter(py::module &);
void bind_Geom2dGcc_QCurve(py::module &);
void bind_Geom2dGcc_QualifiedCurve(py::module &);

PYBIND11_MODULE(Geom2dGcc, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.Geom2dAdaptor");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.GccAna");
py::module::import("OCCT.gp");
py::module::import("OCCT.GccEnt");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.math");

bind_Geom2dGcc_Type3(mod);
bind_Geom2dGcc_Type1(mod);
bind_Geom2dGcc_Type2(mod);
bind_Geom2dGcc(mod);
bind_Geom2dGcc_Circ2d2TanOn(mod);
bind_Geom2dGcc_Circ2d2TanOnGeo(mod);
bind_Geom2dGcc_Circ2d2TanOnIter(mod);
bind_Geom2dGcc_Circ2d2TanRad(mod);
bind_Geom2dGcc_Circ2d2TanRadGeo(mod);
bind_Geom2dGcc_Circ2d3Tan(mod);
bind_Geom2dGcc_Circ2d3TanIter(mod);
bind_Geom2dGcc_Circ2dTanCen(mod);
bind_Geom2dGcc_Circ2dTanCenGeo(mod);
bind_Geom2dGcc_Circ2dTanOnRad(mod);
bind_Geom2dGcc_Circ2dTanOnRadGeo(mod);
bind_Geom2dGcc_CurveTool(mod);
bind_Geom2dGcc_FunctionTanCirCu(mod);
bind_Geom2dGcc_FunctionTanCuCu(mod);
bind_Geom2dGcc_FunctionTanCuCuCu(mod);
bind_Geom2dGcc_FunctionTanCuCuOnCu(mod);
bind_Geom2dGcc_FunctionTanCuPnt(mod);
bind_Geom2dGcc_FunctionTanObl(mod);
bind_Geom2dGcc_IsParallel(mod);
bind_Geom2dGcc_Lin2d2Tan(mod);
bind_Geom2dGcc_Lin2d2TanIter(mod);
bind_Geom2dGcc_Lin2dTanObl(mod);
bind_Geom2dGcc_Lin2dTanOblIter(mod);
bind_Geom2dGcc_QCurve(mod);
bind_Geom2dGcc_QualifiedCurve(mod);

}
