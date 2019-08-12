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

void bind_TopoDSToStep_BuilderError(py::module &);
void bind_TopoDSToStep_MakeFaceError(py::module &);
void bind_TopoDSToStep_MakeWireError(py::module &);
void bind_TopoDSToStep_MakeEdgeError(py::module &);
void bind_TopoDSToStep_MakeVertexError(py::module &);
void bind_TopoDSToStep_FacetedError(py::module &);
void bind_TopoDSToStep(py::module &);
void bind_TopoDSToStep_Root(py::module &);
void bind_TopoDSToStep_Builder(py::module &);
void bind_TopoDSToStep_FacetedTool(py::module &);
void bind_TopoDSToStep_MakeBrepWithVoids(py::module &);
void bind_TopoDSToStep_MakeFacetedBrep(py::module &);
void bind_TopoDSToStep_MakeFacetedBrepAndBrepWithVoids(py::module &);
void bind_TopoDSToStep_MakeGeometricCurveSet(py::module &);
void bind_TopoDSToStep_MakeManifoldSolidBrep(py::module &);
void bind_TopoDSToStep_MakeShellBasedSurfaceModel(py::module &);
void bind_TopoDSToStep_MakeStepEdge(py::module &);
void bind_TopoDSToStep_MakeStepFace(py::module &);
void bind_TopoDSToStep_MakeStepVertex(py::module &);
void bind_TopoDSToStep_MakeStepWire(py::module &);
void bind_TopoDSToStep_Tool(py::module &);
void bind_TopoDSToStep_WireframeBuilder(py::module &);

PYBIND11_MODULE(TopoDSToStep, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.Transfer");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.StepShape");
py::module::import("OCCT.MoniTool");
py::module::import("OCCT.TColStd");

bind_TopoDSToStep_BuilderError(mod);
bind_TopoDSToStep_MakeFaceError(mod);
bind_TopoDSToStep_MakeWireError(mod);
bind_TopoDSToStep_MakeEdgeError(mod);
bind_TopoDSToStep_MakeVertexError(mod);
bind_TopoDSToStep_FacetedError(mod);
bind_TopoDSToStep(mod);
bind_TopoDSToStep_Root(mod);
bind_TopoDSToStep_Builder(mod);
bind_TopoDSToStep_FacetedTool(mod);
bind_TopoDSToStep_MakeBrepWithVoids(mod);
bind_TopoDSToStep_MakeFacetedBrep(mod);
bind_TopoDSToStep_MakeFacetedBrepAndBrepWithVoids(mod);
bind_TopoDSToStep_MakeGeometricCurveSet(mod);
bind_TopoDSToStep_MakeManifoldSolidBrep(mod);
bind_TopoDSToStep_MakeShellBasedSurfaceModel(mod);
bind_TopoDSToStep_MakeStepEdge(mod);
bind_TopoDSToStep_MakeStepFace(mod);
bind_TopoDSToStep_MakeStepVertex(mod);
bind_TopoDSToStep_MakeStepWire(mod);
bind_TopoDSToStep_Tool(mod);
bind_TopoDSToStep_WireframeBuilder(mod);

}
