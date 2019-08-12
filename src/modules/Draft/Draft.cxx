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

void bind_Draft_ErrorStatus(py::module &);
void bind_Draft(py::module &);
void bind_Draft_EdgeInfo(py::module &);
void bind_Draft_FaceInfo(py::module &);
void bind_Draft_IndexedDataMapOfEdgeEdgeInfo(py::module &);
void bind_Draft_IndexedDataMapOfFaceFaceInfo(py::module &);
void bind_Draft_VertexInfo(py::module &);
void bind_Draft_IndexedDataMapOfVertexVertexInfo(py::module &);
void bind_Draft_Modification(py::module &);

PYBIND11_MODULE(Draft, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.gp");
py::module::import("OCCT.Geom");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.BRepTools");
py::module::import("OCCT.TopLoc");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.TopAbs");

bind_Draft_ErrorStatus(mod);
bind_Draft(mod);
bind_Draft_EdgeInfo(mod);
bind_Draft_FaceInfo(mod);
bind_Draft_IndexedDataMapOfEdgeEdgeInfo(mod);
bind_Draft_IndexedDataMapOfFaceFaceInfo(mod);
bind_Draft_VertexInfo(mod);
bind_Draft_IndexedDataMapOfVertexVertexInfo(mod);
bind_Draft_Modification(mod);

}
