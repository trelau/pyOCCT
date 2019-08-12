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

void bind_FEmTool_AssemblyTable(py::module &);
void bind_FEmTool_HAssemblyTable(py::module &);
void bind_FEmTool_ListOfVectors(py::module &);
void bind_FEmTool_ListIteratorOfListOfVectors(py::module &);
void bind_FEmTool_SeqOfLinConstr(py::module &);
void bind_FEmTool_Assembly(py::module &);
void bind_FEmTool_Curve(py::module &);
void bind_FEmTool_ElementaryCriterion(py::module &);
void bind_FEmTool_ElementsOfRefMatrix(py::module &);
void bind_FEmTool_LinearFlexion(py::module &);
void bind_FEmTool_LinearJerk(py::module &);
void bind_FEmTool_LinearTension(py::module &);
void bind_FEmTool_SparseMatrix(py::module &);
void bind_FEmTool_ProfileMatrix(py::module &);

PYBIND11_MODULE(FEmTool, mod) {

py::module::import("OCCT.NCollection");
py::module::import("OCCT.Standard");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.math");
py::module::import("OCCT.PLib");
py::module::import("OCCT.GeomAbs");

bind_FEmTool_AssemblyTable(mod);
bind_FEmTool_HAssemblyTable(mod);
bind_FEmTool_ListOfVectors(mod);
bind_FEmTool_ListIteratorOfListOfVectors(mod);
bind_FEmTool_SeqOfLinConstr(mod);
bind_FEmTool_Assembly(mod);
bind_FEmTool_Curve(mod);
bind_FEmTool_ElementaryCriterion(mod);
bind_FEmTool_ElementsOfRefMatrix(mod);
bind_FEmTool_LinearFlexion(mod);
bind_FEmTool_LinearJerk(mod);
bind_FEmTool_LinearTension(mod);
bind_FEmTool_SparseMatrix(mod);
bind_FEmTool_ProfileMatrix(mod);

}
