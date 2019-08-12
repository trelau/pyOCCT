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

void bind_Bnd_Box(py::module &);
void bind_Bnd_Array1OfBox(py::module &);
void bind_Bnd_Box2d(py::module &);
void bind_Bnd_Array1OfBox2d(py::module &);
void bind_Bnd_Sphere(py::module &);
void bind_Bnd_Array1OfSphere(py::module &);
void bind_Bnd_B2d(py::module &);
void bind_Bnd_B2f(py::module &);
void bind_Bnd_B3d(py::module &);
void bind_Bnd_B3f(py::module &);
void bind_Bnd_HArray1OfBox(py::module &);
void bind_Bnd_BoundSortBox(py::module &);
void bind_Bnd_HArray1OfBox2d(py::module &);
void bind_Bnd_BoundSortBox2d(py::module &);
void bind_Bnd_HArray1OfSphere(py::module &);
void bind_Bnd_OBB(py::module &);
void bind_Bnd_Range(py::module &);
void bind_Bnd_SeqOfBox(py::module &);

PYBIND11_MODULE(Bnd, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.gp");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.TColgp");

bind_Bnd_Box(mod);
bind_Bnd_Array1OfBox(mod);
bind_Bnd_Box2d(mod);
bind_Bnd_Array1OfBox2d(mod);
bind_Bnd_Sphere(mod);
bind_Bnd_Array1OfSphere(mod);
bind_Bnd_B2d(mod);
bind_Bnd_B2f(mod);
bind_Bnd_B3d(mod);
bind_Bnd_B3f(mod);
bind_Bnd_HArray1OfBox(mod);
bind_Bnd_BoundSortBox(mod);
bind_Bnd_HArray1OfBox2d(mod);
bind_Bnd_BoundSortBox2d(mod);
bind_Bnd_HArray1OfSphere(mod);
bind_Bnd_OBB(mod);
bind_Bnd_Range(mod);
bind_Bnd_SeqOfBox(mod);

}
