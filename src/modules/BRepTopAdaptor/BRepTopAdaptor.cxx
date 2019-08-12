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

void bind_BRepTopAdaptor_TopolTool(py::module &);
void bind_BRepTopAdaptor_SeqOfPtr(py::module &);
void bind_BRepTopAdaptor_Tool(py::module &);
void bind_BRepTopAdaptor_MapOfShapeTool(py::module &);
void bind_BRepTopAdaptor_DataMapIteratorOfMapOfShapeTool(py::module &);
void bind_BRepTopAdaptor_FClass2d(py::module &);
void bind_BRepTopAdaptor_HVertex(py::module &);

PYBIND11_MODULE(BRepTopAdaptor, mod) {

py::module::import("OCCT.Adaptor3d");
py::module::import("OCCT.Standard");
py::module::import("OCCT.Adaptor2d");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.gp");
py::module::import("OCCT.TopExp");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.BRepAdaptor");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TopTools");

bind_BRepTopAdaptor_TopolTool(mod);
bind_BRepTopAdaptor_SeqOfPtr(mod);
bind_BRepTopAdaptor_Tool(mod);
bind_BRepTopAdaptor_MapOfShapeTool(mod);
bind_BRepTopAdaptor_DataMapIteratorOfMapOfShapeTool(mod);
bind_BRepTopAdaptor_FClass2d(mod);
bind_BRepTopAdaptor_HVertex(mod);

}
