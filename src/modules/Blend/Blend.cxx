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

void bind_Blend_DecrochStatus(py::module &);
void bind_Blend_Status(py::module &);
void bind_Blend_AppFunction(py::module &);
void bind_Blend_Function(py::module &);
void bind_Blend_FuncInv(py::module &);
void bind_Blend_CSFunction(py::module &);
void bind_Blend_CurvPointFuncInv(py::module &);
void bind_Blend_Point(py::module &);
void bind_Blend_RstRstFunction(py::module &);
void bind_Blend_SequenceOfPoint(py::module &);
void bind_Blend_SurfCurvFuncInv(py::module &);
void bind_Blend_SurfPointFuncInv(py::module &);
void bind_Blend_SurfRstFunction(py::module &);

PYBIND11_MODULE(Blend, mod) {

py::module::import("OCCT.math");
py::module::import("OCCT.Standard");
py::module::import("OCCT.gp");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.Adaptor2d");
py::module::import("OCCT.NCollection");

bind_Blend_DecrochStatus(mod);
bind_Blend_Status(mod);
bind_Blend_AppFunction(mod);
bind_Blend_Function(mod);
bind_Blend_FuncInv(mod);
bind_Blend_CSFunction(mod);
bind_Blend_CurvPointFuncInv(mod);
bind_Blend_Point(mod);
bind_Blend_RstRstFunction(mod);
bind_Blend_SequenceOfPoint(mod);
bind_Blend_SurfCurvFuncInv(mod);
bind_Blend_SurfPointFuncInv(mod);
bind_Blend_SurfRstFunction(mod);

}
