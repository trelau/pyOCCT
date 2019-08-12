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

void bind_BRepBlend_AppFuncRoot(py::module &);
void bind_BRepBlend_AppFunc(py::module &);
void bind_BRepBlend_AppFuncRst(py::module &);
void bind_BRepBlend_AppFuncRstRst(py::module &);
void bind_BRepBlend_AppSurf(py::module &);
void bind_BRepBlend_AppSurface(py::module &);
void bind_BRepBlend_BlendTool(py::module &);
void bind_BRepBlend_Chamfer(py::module &);
void bind_BRepBlend_ChamfInv(py::module &);
void bind_BRepBlend_ChAsym(py::module &);
void bind_BRepBlend_ChAsymInv(py::module &);
void bind_BRepBlend_ConstRad(py::module &);
void bind_BRepBlend_ConstRadInv(py::module &);
void bind_BRepBlend_CSCircular(py::module &);
void bind_BRepBlend_CSConstRad(py::module &);
void bind_BRepBlend_PointOnRst(py::module &);
void bind_BRepBlend_SequenceOfPointOnRst(py::module &);
void bind_BRepBlend_CSWalking(py::module &);
void bind_BRepBlend_CurvPointRadInv(py::module &);
void bind_BRepBlend_EvolRad(py::module &);
void bind_BRepBlend_EvolRadInv(py::module &);
void bind_BRepBlend_Extremity(py::module &);
void bind_BRepBlend_HCurve2dTool(py::module &);
void bind_BRepBlend_HCurveTool(py::module &);
void bind_BRepBlend_Line(py::module &);
void bind_BRepBlend_RstRstConstRad(py::module &);
void bind_BRepBlend_RstRstEvolRad(py::module &);
void bind_BRepBlend_RstRstLineBuilder(py::module &);
void bind_BRepBlend_Ruled(py::module &);
void bind_BRepBlend_RuledInv(py::module &);
void bind_BRepBlend_SequenceOfLine(py::module &);
void bind_BRepBlend_SurfCurvConstRadInv(py::module &);
void bind_BRepBlend_SurfCurvEvolRadInv(py::module &);
void bind_BRepBlend_SurfPointConstRadInv(py::module &);
void bind_BRepBlend_SurfPointEvolRadInv(py::module &);
void bind_BRepBlend_SurfRstConstRad(py::module &);
void bind_BRepBlend_SurfRstEvolRad(py::module &);
void bind_BRepBlend_SurfRstLineBuilder(py::module &);
void bind_BRepBlend_Walking(py::module &);

PYBIND11_MODULE(BRepBlend, mod) {

py::module::import("OCCT.Approx");
py::module::import("OCCT.Standard");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.gp");
py::module::import("OCCT.Blend");
py::module::import("OCCT.math");
py::module::import("OCCT.AppBlend");
py::module::import("OCCT.Adaptor3d");
py::module::import("OCCT.Adaptor2d");
py::module::import("OCCT.BlendFunc");
py::module::import("OCCT.Law");
py::module::import("OCCT.IntSurf");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.Geom");
py::module::import("OCCT.Convert");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.ChFiDS");

bind_BRepBlend_AppFuncRoot(mod);
bind_BRepBlend_AppFunc(mod);
bind_BRepBlend_AppFuncRst(mod);
bind_BRepBlend_AppFuncRstRst(mod);
bind_BRepBlend_AppSurf(mod);
bind_BRepBlend_AppSurface(mod);
bind_BRepBlend_BlendTool(mod);
bind_BRepBlend_Chamfer(mod);
bind_BRepBlend_ChamfInv(mod);
bind_BRepBlend_ChAsym(mod);
bind_BRepBlend_ChAsymInv(mod);
bind_BRepBlend_ConstRad(mod);
bind_BRepBlend_ConstRadInv(mod);
bind_BRepBlend_CSCircular(mod);
bind_BRepBlend_CSConstRad(mod);
bind_BRepBlend_PointOnRst(mod);
bind_BRepBlend_SequenceOfPointOnRst(mod);
bind_BRepBlend_CSWalking(mod);
bind_BRepBlend_CurvPointRadInv(mod);
bind_BRepBlend_EvolRad(mod);
bind_BRepBlend_EvolRadInv(mod);
bind_BRepBlend_Extremity(mod);
bind_BRepBlend_HCurve2dTool(mod);
bind_BRepBlend_HCurveTool(mod);
bind_BRepBlend_Line(mod);
bind_BRepBlend_RstRstConstRad(mod);
bind_BRepBlend_RstRstEvolRad(mod);
bind_BRepBlend_RstRstLineBuilder(mod);
bind_BRepBlend_Ruled(mod);
bind_BRepBlend_RuledInv(mod);
bind_BRepBlend_SequenceOfLine(mod);
bind_BRepBlend_SurfCurvConstRadInv(mod);
bind_BRepBlend_SurfCurvEvolRadInv(mod);
bind_BRepBlend_SurfPointConstRadInv(mod);
bind_BRepBlend_SurfPointEvolRadInv(mod);
bind_BRepBlend_SurfRstConstRad(mod);
bind_BRepBlend_SurfRstEvolRad(mod);
bind_BRepBlend_SurfRstLineBuilder(mod);
bind_BRepBlend_Walking(mod);

}
