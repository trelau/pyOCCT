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

void bind_BRepAlgoAPI_Algo(py::module &);
void bind_BRepAlgoAPI_BuilderAlgo(py::module &);
void bind_BRepAlgoAPI_BooleanOperation(py::module &);
void bind_BRepAlgoAPI_Check(py::module &);
void bind_BRepAlgoAPI_Common(py::module &);
void bind_BRepAlgoAPI_Cut(py::module &);
void bind_BRepAlgoAPI_Defeaturing(py::module &);
void bind_BRepAlgoAPI_Fuse(py::module &);
void bind_BRepAlgoAPI_Section(py::module &);
void bind_BRepAlgoAPI_Splitter(py::module &);

PYBIND11_MODULE(BRepAlgoAPI, mod) {

py::module::import("OCCT.BRepBuilderAPI");
py::module::import("OCCT.BOPAlgo");
py::module::import("OCCT.Standard");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.BRepTools");
py::module::import("OCCT.gp");
py::module::import("OCCT.Geom");

bind_BRepAlgoAPI_Algo(mod);
bind_BRepAlgoAPI_BuilderAlgo(mod);
bind_BRepAlgoAPI_BooleanOperation(mod);
bind_BRepAlgoAPI_Check(mod);
bind_BRepAlgoAPI_Common(mod);
bind_BRepAlgoAPI_Cut(mod);
bind_BRepAlgoAPI_Defeaturing(mod);
bind_BRepAlgoAPI_Fuse(mod);
bind_BRepAlgoAPI_Section(mod);
bind_BRepAlgoAPI_Splitter(mod);

}
