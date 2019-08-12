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

void bind_BRepFeat_StatusError(py::module &);
void bind_BRepFeat_PerfSelection(py::module &);
void bind_BRepFeat_Status(py::module &);
void bind_BRepFeat(py::module &);
void bind_BRepFeat_Builder(py::module &);
void bind_BRepFeat_Form(py::module &);
void bind_BRepFeat_Gluer(py::module &);
void bind_BRepFeat_MakeCylindricalHole(py::module &);
void bind_BRepFeat_MakeDPrism(py::module &);
void bind_BRepFeat_RibSlot(py::module &);
void bind_BRepFeat_MakeLinearForm(py::module &);
void bind_BRepFeat_MakePipe(py::module &);
void bind_BRepFeat_MakePrism(py::module &);
void bind_BRepFeat_MakeRevol(py::module &);
void bind_BRepFeat_MakeRevolutionForm(py::module &);
void bind_BRepFeat_SplitShape(py::module &);

PYBIND11_MODULE(BRepFeat, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.gp");
py::module::import("OCCT.Geom");
py::module::import("OCCT.BRepTopAdaptor");
py::module::import("OCCT.Geom2dAdaptor");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.BOPAlgo");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.BRepBuilderAPI");
py::module::import("OCCT.TColGeom");
py::module::import("OCCT.LocOpe");
py::module::import("OCCT.BRepAlgoAPI");

bind_BRepFeat_StatusError(mod);
bind_BRepFeat_PerfSelection(mod);
bind_BRepFeat_Status(mod);
bind_BRepFeat(mod);
bind_BRepFeat_Builder(mod);
bind_BRepFeat_Form(mod);
bind_BRepFeat_Gluer(mod);
bind_BRepFeat_MakeCylindricalHole(mod);
bind_BRepFeat_MakeDPrism(mod);
bind_BRepFeat_RibSlot(mod);
bind_BRepFeat_MakeLinearForm(mod);
bind_BRepFeat_MakePipe(mod);
bind_BRepFeat_MakePrism(mod);
bind_BRepFeat_MakeRevol(mod);
bind_BRepFeat_MakeRevolutionForm(mod);
bind_BRepFeat_SplitShape(mod);

}
