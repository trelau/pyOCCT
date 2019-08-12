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
#include <BVH_Types.hxx>
#include <Standard_TypeDef.hxx>

PYBIND11_MAKE_OPAQUE(std::vector<NCollection_Vec3<int>, std::allocator<NCollection_Vec3<int> > >)

void bind_BVH_Array3i(py::module &mod){

py::bind_vector<std::vector<NCollection_Vec3<int>, std::allocator<NCollection_Vec3<int> > >>(mod, "BVH_Array3i");

}