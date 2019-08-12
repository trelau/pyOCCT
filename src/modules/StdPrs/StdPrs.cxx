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

void bind_StdPrs_Volume(py::module &);
void bind_StdPrs_BndBox(py::module &);
void bind_StdPrs_Curve(py::module &);
void bind_StdPrs_DeflectionCurve(py::module &);
void bind_StdPrs_HLRPolyShape(py::module &);
void bind_StdPrs_HLRShape(py::module &);
void bind_StdPrs_HLRToolShape(py::module &);
void bind_StdPrs_ToolTriangulatedShape(py::module &);
void bind_StdPrs_Isolines(py::module &);
void bind_StdPrs_Plane(py::module &);
void bind_StdPrs_ToolPoint(py::module &);
void bind_StdPrs_Point(py::module &);
void bind_StdPrs_PoleCurve(py::module &);
void bind_StdPrs_ShadedShape(py::module &);
void bind_StdPrs_ShadedSurface(py::module &);
void bind_StdPrs_ToolRFace(py::module &);
void bind_StdPrs_ToolVertex(py::module &);
void bind_StdPrs_Vertex(py::module &);
void bind_StdPrs_WFDeflectionRestrictedFace(py::module &);
void bind_StdPrs_WFDeflectionSurface(py::module &);
void bind_StdPrs_WFPoleSurface(py::module &);
void bind_StdPrs_WFRestrictedFace(py::module &);
void bind_StdPrs_WFShape(py::module &);
void bind_StdPrs_WFSurface(py::module &);

PYBIND11_MODULE(StdPrs, mod) {

py::module::import("OCCT.Prs3d");
py::module::import("OCCT.Standard");
py::module::import("OCCT.Bnd");
py::module::import("OCCT.Adaptor3d");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.HLRAlgo");
py::module::import("OCCT.BRepAdaptor");
py::module::import("OCCT.HLRBRep");
py::module::import("OCCT.Poly");
py::module::import("OCCT.Geom");
py::module::import("OCCT.TopLoc");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.gp");
py::module::import("OCCT.BRep");
py::module::import("OCCT.Graphic3d");
py::module::import("OCCT.Adaptor2d");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.TopExp");
py::module::import("OCCT.Geom2dAdaptor");
py::module::import("OCCT.TopTools");

bind_StdPrs_Volume(mod);
bind_StdPrs_BndBox(mod);
bind_StdPrs_Curve(mod);
bind_StdPrs_DeflectionCurve(mod);
bind_StdPrs_HLRPolyShape(mod);
bind_StdPrs_HLRShape(mod);
bind_StdPrs_HLRToolShape(mod);
bind_StdPrs_ToolTriangulatedShape(mod);
bind_StdPrs_Isolines(mod);
bind_StdPrs_Plane(mod);
bind_StdPrs_ToolPoint(mod);
bind_StdPrs_Point(mod);
bind_StdPrs_PoleCurve(mod);
bind_StdPrs_ShadedShape(mod);
bind_StdPrs_ShadedSurface(mod);
bind_StdPrs_ToolRFace(mod);
bind_StdPrs_ToolVertex(mod);
bind_StdPrs_Vertex(mod);
bind_StdPrs_WFDeflectionRestrictedFace(mod);
bind_StdPrs_WFDeflectionSurface(mod);
bind_StdPrs_WFPoleSurface(mod);
bind_StdPrs_WFRestrictedFace(mod);
bind_StdPrs_WFShape(mod);
bind_StdPrs_WFSurface(mod);

}
