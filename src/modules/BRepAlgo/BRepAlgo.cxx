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

void bind_BRepAlgo_CheckStatus(py::module &);
void bind_BRepAlgo_Image(py::module &);
void bind_BRepAlgo(py::module &);
void bind_BRepAlgo_AsDes(py::module &);
void bind_BRepAlgo_BooleanOperation(py::module &);
void bind_BRepAlgo_DSAccess(py::module &);
void bind_BRepAlgo_BooleanOperations(py::module &);
void bind_BRepAlgo_Common(py::module &);
void bind_BRepAlgo_Cut(py::module &);
void bind_BRepAlgo_DataMapOfShapeBoolean(py::module &);
void bind_BRepAlgo_DataMapIteratorOfDataMapOfShapeBoolean(py::module &);
void bind_BRepAlgo_DataMapOfShapeInterference(py::module &);
void bind_BRepAlgo_DataMapIteratorOfDataMapOfShapeInterference(py::module &);
void bind_BRepAlgo_EdgeConnector(py::module &);
void bind_BRepAlgo_FaceRestrictor(py::module &);
void bind_BRepAlgo_Fuse(py::module &);
void bind_BRepAlgo_Loop(py::module &);
void bind_BRepAlgo_NormalProjection(py::module &);
void bind_BRepAlgo_Section(py::module &);
void bind_BRepAlgo_SequenceOfSequenceOfInteger(py::module &);
void bind_BRepAlgo_Tool(py::module &);

PYBIND11_MODULE(BRepAlgo, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.BRepBuilderAPI");
py::module::import("OCCT.TopOpeBRepBuild");
py::module::import("OCCT.TopOpeBRepDS");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.TopOpeBRep");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.Adaptor3d");
py::module::import("OCCT.gp");
py::module::import("OCCT.Geom");

bind_BRepAlgo_CheckStatus(mod);
bind_BRepAlgo_Image(mod);
bind_BRepAlgo(mod);
bind_BRepAlgo_AsDes(mod);
bind_BRepAlgo_BooleanOperation(mod);
bind_BRepAlgo_DSAccess(mod);
bind_BRepAlgo_BooleanOperations(mod);
bind_BRepAlgo_Common(mod);
bind_BRepAlgo_Cut(mod);
bind_BRepAlgo_DataMapOfShapeBoolean(mod);
bind_BRepAlgo_DataMapIteratorOfDataMapOfShapeBoolean(mod);
bind_BRepAlgo_DataMapOfShapeInterference(mod);
bind_BRepAlgo_DataMapIteratorOfDataMapOfShapeInterference(mod);
bind_BRepAlgo_EdgeConnector(mod);
bind_BRepAlgo_FaceRestrictor(mod);
bind_BRepAlgo_Fuse(mod);
bind_BRepAlgo_Loop(mod);
bind_BRepAlgo_NormalProjection(mod);
bind_BRepAlgo_Section(mod);
bind_BRepAlgo_SequenceOfSequenceOfInteger(mod);
bind_BRepAlgo_Tool(mod);

}
